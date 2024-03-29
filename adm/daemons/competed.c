// competed.c
// writed by smallfish

#include <ansi.h>

inherit F_DBASE;

#define ENTRY_ROOM      "/d/biwu/biwu_dating"
#define FIGHT_ROOM      "/d/biwu/lunjian1"
#define GAOSHOU_OBJ     "/clone/misc/gaoshou"
#define GAOSHOU_DIR     "/data/gaoshou/"
#define TEMP_OBJ        "/clone/misc/temp_gaoshou"

nosave object challenger = 0;  // 挑战者
nosave object competitor = 0;  // 被挑战着

// 返回值 1 -- 可以上去
// 返回值 2 -- 正在比武
// 返回值 3 -- 还没开放
nosave int state = 1;
nosave int times = 3;
nosave int top_num = 10;
nosave string top_id = "";
nosave object *total = ({ });
nosave mapping tops = ([ ]);
nosave mapping tmp_top = ([ ]);

string query_top_id() { return top_id; }
string query_new_id()
{
        // debug_message("challenger = " + challenger);
        if (challenger)
                return challenger->query("id");
        else
                return "VOID";
}

mapping query_tops() { return tops; }

string *armor_type = ({ "armor", "boots", "cloth",
                        "hands", "head", "neck",
                        "shield", "surcoat","waist",
                        "wrists" });

int get_tops();
int save_tops();
private void auto_check();
int check_out(object me);
int check_quit(object me);
private void init_player(object me);
private void restore_status(object me);
int join_competition(object ob);
private int start_competition(int top_num);
private int do_competition(object ob1, object ob2);
private int finish_competition();
void restore_competition();
private void message_competition(string msg);

int clean_up() { return 1; }

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "比武精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "演武系统已经启动。");
        get_tops();
}

void remove(string euid)
{
        if (! this_player())
                return;

        if (state = 2 && sizeof(total) > 0)
              error("比武精灵：目前还有玩家正在挑战十大高手，你不能摧毁比武精灵。\n");
}

private void heart_beat()
{
        if (sizeof(total))
                auto_check();
}

private void auto_check()
{
        object ob;
        string room;
        object *lost;
        int i;

        lost = ({ });
        for (i = 0; i < sizeof(total); i++)
        {
                if (! objectp(total[i]))
                {
                        total[i] = 0;
                        continue;
                }
                room = base_name(environment(total[i]));
                if (! sscanf(room, "/d/biwu/lunjia%*s"))
                {
                        // not in pk room
                        restore_status(total[i]);
                        // total[i]->delete("total_hatred");
                        total[i] = 0;
                        continue;
                }
                if (total[i]->is_net_dead())
                {
                        lost += ({ total[i] });
                        break;
                }

                if (total[i]->query("gin") < 1 || total[i]->query("ken") < 1)
                {
                        lost += ({ total[i] });
                        break;
                }
        }

        // kickout the players who lost competition
        foreach (ob in lost)
                check_out(ob);

        total -= ({ 0 });

        if (state == 2)
        {
                if (sizeof(total) < 1)
                {
                        restore_competition();
                        finish_competition();
                        return;
                }
        }

        if (state != 2)
        {
                // set_heart_beat(0);
                return;
        }

        if (sizeof(total) == 1)
        {
                if (userp(total[0]))
                {
                        top_num--;
                        start_competition(top_num);
                }
                else
                        finish_competition();
        }
}

int check_out(object me)
{
        object ob;
        mapping my;
        string msg;

        if (userp(me))
        {
                my = me->query_entire_dbase();
                my["eff_kee"] = my["max_kee"];
                my["eff_gin"] = my["max_gin"];
                my["kee"] = 1;
                my["gin"] = 1;

                tell_object(me, HIR "\n你觉得眼前一阵模糊...这下完了！\n" NOR);
                if (ob = me->query_last_damage_from())
                {
                        msg = "听说" + me->name(1) + HIY "惨遭" + ob->name(1) + HIY "的毒手，被一脚踢下擂台。";
                } else
                        msg = "听说" + me->name(1) + HIY "运气不佳，本领有限、已经败下擂台。";
                message_competition(msg);

                restore_status(me);
                total -= ({ me });
                me->move(ENTRY_ROOM);
                message("vision", "一个黑影倏的窜了出来，随即就是“啪”的"
                        "一声，就见" + me->name() +"摔倒了地上，一副半死不"
                        "活的样子。\n", environment(me), ({ me }));
                tell_object(me, "半昏半迷中，你觉得被人拎了起来，又"
                        "重重的摔倒了地上。\n");
                if (! living(me))
                        me->revive();
                return 1;
        } else
        {
                message_vision(NOR "\n$N膝盖一软，单膝着地，又强撑着站起身来，口中却喷出一口"
                        HIR "鲜血" NOR "，黯然转身离去！\n\n" NOR, me);
                msg = HIY "恭喜" + NOR + HIR + challenger->name(1) + NOR +
                      HIY "比武战胜" + NOR + HIR + me->name(1) + NOR +
                      HIY "！！\n" NOR;
                message_competition(msg);

                restore_status(me);
                total -= ({ me });
                destruct(me);
                return 1;
        }
}

int check_quit(object me)
{
        message_competition("听说" + me->name(1) +
                            "临阵脱逃，溜走了。");
        restore_status(me);
        if (arrayp(total))
                total -= ({ me });
        tell_object(me, "你决定弃权，逃了下去。\n");

        // continue run quit function
        me->move(ENTRY_ROOM);
        message("vision", "只见" + me->name() + "脸色非常难看的跑了下来。\n",
                environment(me), ({ me }));
        return 1;
}

int join_competition(object ob)
{
        int exp;

        if (state == 2 || objectp(challenger))
                return notify_fail("现在擂台正在举行比武，你还是等会吧。\n");

        if (state == 3)
                return notify_fail("擂台现在已经关闭了，你跑来干什么？\n");

        exp = ob->query("combat_exp");
        if (exp < 100000)
                return notify_fail("你还是算了吧，你这点经验就别进去现眼了。\n");

        if (ob->query_condition("killer", 1))
                return notify_fail("你正在被官府通缉，所以不能参加屠人大赛。\n");

        if (! get_tops())
                return notify_fail("对不起，擂台上比武排名记录有错误，请联系巫师。\n");

        if (ob->query_condition())
                return notify_fail("你现在状态不佳，还是别进去了。\n");

        if (! arrayp(total))
                total = ({ ob });
        else
        if (member_array(ob, total) == -1)
                total += ({ ob });


        init_player(ob);
        // set_heart_beat(1);

        tmp_top["id"] = ob->query("id");
        tmp_top["title"] = ob->short(1);
        challenger = ob;
        top_num = 9;
        start_competition(top_num);
        return 1;
}

private void init_player(object me)
{
        me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
        me->set_override("die", (: call_other, __FILE__, "check_out" :));
        me->set_override("quit", (: call_other, __FILE__, "check_quit" :));
        me->set_temp("backup/killer", me->query_killer());
        me->set_temp("backup/want", me->query_want());

        me->move(FIGHT_ROOM);
        if (userp(me))
                message_vision(HIW "$N飞身跳上擂台，周围响起一片叫好声。\n\n", me);
        else
                message_vision(HIW "只听的一声锣响，$N从后台大步走了出来，环顾一下四方。\n\n", me);
        me->set("backup/condition", me->query_condition());
        me->clear_condition();
}

private void restore_status(object me)
{
        mapping cnd;
        string *ks;
        int j, k;
        int i;

        me->delete_override("unconcious");
        me->delete_override("die");
        me->delete_override("quit");
	me->remove_all_enemy(1);
	me->remove_all_killer();
        j = (int)me->query_condition("putizi_drug");
        k = (int)me->query_condition("pill_drug");
	me->clear_condition();
	me->receive_damage("qi", 0);
        me->apply_killer(me->query_temp("backup/killer"));
        me->apply_want(me->query_temp("backup/want"));

        cnd = me->query("backup/condition");
        me->delete("backup/condition");
	me->delete_temp("block_msg/all");
        if (j > 0)
        me->apply_condition("putizi_drug", j);
        if (k > 0)
        me->apply_condition("pill_drug", k);
        if (! mapp(cnd)) return;
        ks = keys(cnd);
        for (i = 0; i < sizeof(ks); i++)
                me->apply_condition(ks[i], cnd[ks[i]]);
}

private int start_competition(int top_num)
{
        int i;
        object ob;

        if (top_num < 0)
        {
                finish_competition();
                return 1;
        }
        if (! challenger)
        {
                finish_competition();
                return 1;
        }

        top_id = tops[top_num]["id"];
        if (top_id == challenger->query("id"))
        {
                top_num--;
                start_competition(top_num);
                return 1;
        }

        ob = new(GAOSHOU_OBJ);

        if (! arrayp(total))
                total = ({ ob });
        else
        if (member_array(ob, total) == -1)
                total += ({ ob });

        init_player(ob);

        competitor = ob;
        state = 2;
        set_heart_beat(1);
        do_competition(challenger, competitor);
        return 1;
}

private int do_competition(object ob1, object ob2)
{
        object room;

        if (! ob1 || ! ob2)
        {
                finish_competition();
                return 1;
        }

        if (! room = find_object(FIGHT_ROOM))
                room = load_object(FIGHT_ROOM);
        if (present(ob1, room) && present(ob2, room))
        {
                if (! ob1->is_killing(ob2) || ! ob2->is_killing(ob1))
                {
                        if (times > 0)
                        {
                                tell_object(ob1, "\t\t" + HIR + "===" + CHINESE_D->chinese_number(times) + "===\n\n" + NOR);
                                tell_object(ob2, "\t\t" + HIR + "===" + CHINESE_D->chinese_number(times) + "===\n\n" + NOR);
                                times--;
                                call_out("do_competition", 3, ob1, ob2);
                                return 1;
                        } else
                        {
                                times = 3;
                                tell_room(room, HIY "\t-------  开     始  -------\n\n" NOR);
                                message_vision(HIW "\n$N对着$n冷哼一声：既然不要命，那就放马过来吧！\n", ob2, ob1);
                        }
                }

                if (! ob2->is_killing(ob1))
                        ob2->kill_ob(ob1);
                if (! ob1->is_killing(ob2))
                        ob1->kill_ob(ob2);
        }

        return 1;
}

private int finish_competition()
{
        int i, j;
        int mingci, old_mingci;
        string from_file, to_file, temp_file;
        string weapon_file, armor_file, *carry_ob;
        string msg;
        object weapon, armor, temp_ob;

        set_heart_beat(0);

        if (objectp(competitor))
                destruct(competitor);

        if (! objectp(challenger))
        {
                restore_competition();
                return 1;
        }

        mingci = top_num + 1;

        if (base_name(environment(challenger)) == FIGHT_ROOM && top_num < 0)
        {
                restore_status(challenger);
                challenger->move(ENTRY_ROOM);
                message_vision(HIW "$N哈哈一笑，轻身飘下了擂台。\n" NOR, challenger);
                msg = HIY + challenger->name(1) + "打败所有高手，大笑着飞身飘下擂台！\n" NOR;
                message_competition(msg);
        }

        /*
        if (mingci != 0)
        {
                msg = HIY + challenger->name(1) + "被几个大汉抬下了擂台！\n" NOR;
                message_competition(msg);
        }
        */

        if (mingci > 9)
        {
                restore_competition();
                return 1;
        }
        old_mingci = 100;
        for (i = 0;i < sizeof(tops);i++)
        {
                if (tops[i]["id"] == challenger->query("id"))
                {
                        old_mingci = i;
                        break;
                }
        }
        if (old_mingci == 100)
                old_mingci = 9;
        else
        if (mingci >= old_mingci)
        {
                restore_competition();
                return 1;
        }

        if (old_mingci == 9)
        {
                //删除老天下第十的资料
                temp_file = GAOSHOU_DIR + "npc/" + tops[9]["id"] + ".o";
                if (file_size(temp_file) >= 0)
                        rm(temp_file);
                temp_file = GAOSHOU_DIR + "weapon/" + tops[9]["id"] + "-weapon.c";
                if (file_size(temp_file) >= 0)
                        rm(temp_file);
                for (i = 0;i < sizeof(armor_type);i++)
                {
                        temp_file = GAOSHOU_DIR + "weapon/" + tops[9]["id"] + "-" + armor_type[i] + ".c";
                        if (file_size(temp_file) >= 0)
                                rm(temp_file);
                }
        }

        carry_ob = ({});
        from_file = challenger->query_save_file() + ".o";
        to_file = GAOSHOU_DIR + "npc/" + challenger->query("id") + ".o";
        for (i = old_mingci;i >= 0;i--)
        {
                if (i < mingci) break;
                if (i == mingci)
                {
                        tops[i] = tmp_top;
                        //复制玩家档案
                        cp(from_file, to_file);

                        //修改新的档案属性
                        temp_ob = new(TEMP_OBJ);
                        temp_ob->delete_status();
                        //复制武器
                        if (objectp(weapon = challenger->query_temp("weapon")) &&
			    (! weapon->is_no_clone() ||
                             weapon->is_item_make()))
                        {
                                weapon_file = base_name(weapon);
                                from_file = weapon_file + ".c";
                                to_file = GAOSHOU_DIR + "weapon/" +
                                          challenger->query("id") +
                                          "-weapon.c";
                                cp(from_file,to_file);
                                if (strlen(weapon_file) > 11 &&
                                    weapon_file[0..10] == "/data/item/")
                                {
                                        temp_ob->set("can_summon/" + challenger->query("id") +
                                                     "-weapon",to_file);
                                } else carry_ob += ({ to_file });
                        }

                        //复制防具
                        for (j = 0;j<sizeof(armor_type);j++)
                        {
                                if (objectp(armor = challenger->query_temp("armor/"+armor_type[j])))
                                {
                                        armor_file = base_name(armor);
                                        if (strlen(armor_file) > 11 &&
                                            armor_file[0..10] == "/data/item/")
                                        {
                                                from_file = armor_file + ".c";
                                                to_file = GAOSHOU_DIR + "weapon/" +
                                                          challenger->query("id") +
                                                          "-" + armor_type[j] + ".c";
                                                cp(from_file,to_file);
                                                temp_ob->set("can_summon/" + challenger->query("id") +
                                                             "-" + armor_type[j],to_file);
                                        } else carry_ob += ({ armor_file });
                                }
                        }

                        if (sizeof(carry_ob))
                                temp_ob->set("carry_ob",carry_ob);

                        temp_ob->set("auto_perform", 1);
                        temp_ob->save();
                        destruct(temp_ob);
                        break;
                }
                tops[i] = tops[i - 1];
        }
        save_tops();
        msg = HIY "恭喜" + challenger->name(1) +
              HIY "荣登" + HIG + "天下第" + chinese_number(mingci + 1) +
              NOR + HIY + "的宝座！\n" NOR;
        message_competition(msg);
        get_tops();
        restore_competition();
        return 1;
}

void restore_competition()
{
        state = 1;
        challenger = 0;
        competitor = 0;
        times = 3;
        total = ({ });
        tmp_top = ([ ]);
        top_num = 10;
        top_id = "";
        return;
}

int get_tops()
{
        int i;
        string *str, *line;
        mapping top;

        tops = ([ ]);

        if (file_size(GAOSHOU_DIR + "gaoshou_tops") < 0)
        {
                for (i = 0; i < 10; i ++)
                {
                        top = ([ ]);
                        top["id"] = "test";
                        top["title"] = "「巫师测试人物」测试(test)";
                        tops += ([ i : top ]);
                }
                return 1;
        }

        str = explode(read_file(GAOSHOU_DIR + "gaoshou_tops"), "\n");
        // if (sizeof(str) != 10)
                // return 0;

        for (i = 0; i < sizeof(str); i ++)
        {
                top = ([ ]);
                line = explode(str[i], "|");
                if (sizeof(line) != 2) return 0;
                top["id"] = line[0];
                top["title"] = line[1];
                tops += ([ i : top ]);
        }
        save_tops();
        return 1;
}

int save_tops()
{
        int i;
        string str;
        str = "";

        for (i = 0;i < sizeof(tops);i ++)
        {
                str += tops[i]["id"] + "|" + replace_string(tops[i]["title"], "|", "");
                if (i + 1 != sizeof(tops))
                        str += "\n";
        }
        write_file(GAOSHOU_DIR + "gaoshou_tops", str, 1);
        return 1;
}

private void message_competition(string msg)
{
        message("sys", HIY "【武林争霸】" + msg + "\n" NOR, users());
}
