// user.c

#include <origin.h>
#include <user.h>
#include <ansi.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_ENCODING;

nosave int last_age_set;
nosave int pk_msg_time;//pk 消息间隔时间。add by yanyan

void create()
{
    ::create();
    set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
    set_temp("terminal_type", term_type);
    message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}
//通缉犯 消息 add by yanyan
int show_pk_msg(object me)
{
    object *usr;

    pk_msg_time++;
    if(pk_msg_time>=20)
        pk_msg_time = 0;
    else
        return 1;

    usr=users();
    usr=filter_array(usr,"filter_listen",this_object());
    message("vision",HIM"【谣言】某人：据说"+me->name()+HIM+"在"+
         MISC_D->find_place(environment(me))+HIM+"一带活动。\n"NOR,usr);
    return 1;
}

int filter_listen(object ob)
{
  if(ob==this_object()) return 0;
  return 1;
}

void reset()
{

    if(query("killer_time")&&(time()-query("killer_time")>3600)){
        delete("killer");
        delete("killer_time");
    }

    if(query("pker")&&query("pker_time")&&(time()-query("pker_time")>=3600*query("pker"))){
        delete("pker");
        delete("pker_time");
        message("vision",HIR"【大唐风云】"+HIY+"据说对"+HIG+query("name")+HIY+"的通缉令解除了！\n"NOR,users());
    }
    if(query("zuolao")&&(time()-query("zuolao_time")>=3600*query("zuolao"))){
        delete("zuolao");
        delete("zuolao_time");
        move("/d/yangzhou/hotel");
        message("vision",HIR"【大唐风云】"+HIY+"据说"+HIG+query("name")+HIY+"刑满释放了！\n"NOR,users());
    }

    if(query("thief"))
     add("thief",-1);
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
    string id;

    id = geteuid();
    if( !id ) id = getuid();
    if( !stringp(id) ) return 0;
    return sprintf(DATA_DIR "user/%c/%s", id[0],id);
}

int save()
{
    int res;

    save_autoload();

    res = ::save();
    clean_up_autoload();		// To save memory
    return res;
}

// This function updates player's age, called by heart_beat()

void clear_last_age()
{
    last_age_set=0;
}

void update_age()
{
    //第一岁 24 小时，第二岁 25小时，第三岁 26 小时 ... ...
       if(environment()&&environment()->query("no_time")){

        last_age_set = time();
        return;
    }
    if( !last_age_set ) last_age_set = time();
    add("mud_age", time() - last_age_set);
    last_age_set = time();

    if(query("age")>0)//第一次登陆
        set("old_age",query("age"));
    else
        set("old_age",10);

    set("age", 10 + (int)query("age_modify")/86400 +
                            query("add_age")+
                          (query("mud_age")-query("old_mud_age"))/
                          (86400+(query("age")-9)*3600) );

    if(query("age")>=200)
      set("age",query("old_age"));
    if(query("age")>query("old_age")){
        add("add_age",query("age")-query("old_age"));
        set("old_mud_age",query("mud_age"));
    }
    if(query("age")>query("old_age")&&
    query("family/family_name")!="慈航静斋"){
     set("kar",10+random(11)+random(11));
     tell_object(this_object(),HIY"\n\n又是一岁过去了，不知这一岁的运气会怎么样。\n\n"NOR);
    }


}
void check_skills(object ob)
{
  int i;
  mapping skill;mixed *skills;
  skill=ob->query_skills();
if(!skill) return;
  skills=keys(skill);
  for(i=0;i<sizeof(skills);i++)
  {
    if(ob->query_skill(skills[i],1)>ob->query("max_pot")-100&&
    SKILL_D(skills[i])->query_type()!="knowledge"&&
    SKILL_D(skills[i])->query_type()!="literate")
    ob->set_skill(skills[i],ob->query("max_pot")-100);
   }
  return;
}

void check_force(object ob)
{
   if(ob->query("max_force")>ob->query_skill("force",1)*63/4){
     ob->set("max_force",ob->query_skill("force",1)*63/4);
     ob->set("force",ob->query_skill("force",1)*63/4);
     log_file("bug_force_player",ob->query("name")+"   "+ob->query("id")+"。\n");
     tell_object(ob,"\n\n你的内力上限超过正常数值，现在被大神降低了！\n"+
                    "你的账号已经被记录在案！\n\n");
   }
   return;
}


void setup()
{
    // We want set age first before new player got initialized with
    // random age.

    update_age();

    ::setup();
    restore_autoload();

    check_skills(this_object());
    check_force(this_object());

}

private void user_dump(int type)
{
    switch(type) {
        case DUMP_NET_DEAD:
            tell_room( environment(), query("name") + "断线超过 "
                + NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
            this_object()->enable_player();
            command("quit");
            break;
        case DUMP_IDLE:
            if( !wizardp(this_object())) {
            tell_object( this_object(), "对不起，您已经发呆超过 "
                + IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
            tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
                + "化为一堆飞灰，消失了。\n", ({this_object()}));
            this_object()->enable_player();
            this_object()->start_busy(0);
            command("quit");
            }
            break;
        default: return;
    }
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
    object link_ob;

    set_heart_beat(0);
    if( objectp(link_ob = query_temp("link_ob")) )
        destruct(link_ob);

    // Stop fighting, we'll be back soon.
    remove_all_enemy();

    set_temp("netdead", 1);
    if( userp(this_object()) ) {
        call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
        tell_room(environment(), query("name") + "断线了。", this_object());
        CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
    } else {
        command("quit");
    }
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
    set_heart_beat(1);
    set_temp("netdead",0);
    remove_call_out("user_dump");
    tell_object(this_object(), "重新连线完毕。\n");
}
