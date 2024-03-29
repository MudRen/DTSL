// last modify by mudadm 5-7-1999
//last modify by yanyan.for dtsl.
// #pragma optimize

#include <dbase.h>
#include <room.h>
#include <ansi.h>

#define TIME_TICK1 ((time()-900000000)*60)
#define MAX_LIGHT_TIME 1200
nosave int weight = 0;
nosave int encumb = 0, max_encumb = 0;
void dest_obj(object obj);
void get_cloth(object user);//add by yanyan

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

//added by mudadm
nosave int max_items=10; // default max_items.
nomask void set_max_items(int e) {max_items=e;}
nomask int query_max_items() {return max_items;}


nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }
nomask void add_encumbrance(int w)
{
        encumb += w;
        if( encumb < 0 )
                log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
        if( encumb > max_encumb ) this_object()->over_encumbrance();
        if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
        if( !interactive(this_object()) ) return;
        tell_object(this_object(), "你的负荷过重了！\n");
}

nomask int query_weight() { return weight; }
nomask void set_weight(int w)
{
        if( !environment() ) {
                weight = w;
                return;
        }
        if( w!=weight ) environment()->add_encumbrance( w - weight );
        weight = w;
}


// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

string ride_suffix (object me)
{
 string ridemsg = 0;
 object ridee = 0;

 ridee = me->ride();
 if (ridee)
  ridemsg = ridee->query("ride/msg")+"在"+ridee->name()+"上";
 return ridemsg;
 }

object ride()
{
 object me = this_object();
 string ridemsg = "";
 object ridee;

 if (ridee = me->query_temp("ridee")) {
  if ((environment(ridee) != environment(me) &&
     environment(ridee) != me) ||
    (ridee->is_character() && ! living(ridee))) {
   me->set_temp("ridee",0);
   ridee->set_temp("rider",0);
   ridee = 0;
  }
 }
 if (! ridee) {
  me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
  me->set_temp("ride/dodge",0);
 }
 return ridee;
}
varargs int move(mixed dest, int silently)
{
        object ob,env;object where;mapping exits;string *dirs;int i;object *inv;
        object env1,env2,ob3;   //added by puff
        string type1,type2,type3;       //added by puff
        int flag1,flag2,flag3;  //added by puff
        string position, action;string str;
        where=environment();
        // If we are equipped, unequip first.
        if( query("equipped") && !this_object()->unequip() )
                return notify_fail("你没有办法取下这样东西。\n");

        // Find the destination ob for moving.
        if( objectp(dest) )
                ob = dest;
        else if( stringp(dest) ) {
                call_other(dest, "???");
                ob = find_object(dest);
                if(!ob) return notify_fail("move: destination unavailable.\n");
        } else
                return notify_fail(sprintf("move: invalid destination %O.\n", dest));

        // Check if the destination ob can hold this object.
        // Beforce checking it, we check if the destination is environment of
        // this_object() (or environment of its environment). If it is, then
        // this could be like get something from a bag carried by the player.
        // Since the player can carry the bag, we assume he can carry the this
        // object in the bag and encumbrance checking is unessessary.
        env = this_object();
        while(env ==environment(env)) if( env==ob ) break;
        if( env && ((int)ob->query_encumbrance() + weight()
                > (int)ob->query_max_encumbrance()||sizeof(all_inventory(ob))>=30) ) {
                if( userp(ob) ) {
                        this_object()->move(environment(ob));
//                        return notify_fail( "你拿的东西太多了，再也拿不动"+this_object()->name()+"。\n"+this_object()->name()+ "掉在了地上。\n");
                        tell_object(ob,"你拿的东西太多了，再也拿不动"+this_object()->name()+"。\n"+this_object()->name()+ "掉在了地上。\n");
                        return 0;
                } else {
                    switch ( (string)ob->query("position") ) {
                    case "on":
                        position = "上";
                        break;
                    case "under":
                        position = "下面";
                        break;
                    case "behind":
                        position = "后面";
                        break;
                    case "inside":
                        position = "里";
                        break;
                    default:
                        position = "里";
                        break;
                    } /* switch */
                    if(!( action = (string)dest->query("put_action") ) )
                        action = "放";
                            return notify_fail( ob->name()+position+ action+"不了"+this_object()->name() + "。\n");
                      //    return notify_fail( this_object()->name() + "对" + ob->name() + "而言太重了。\n");
                }
        }

        if( userp(ob)&&
           (int)ob->query_encumbrance() + weight()
                > (int)ob->query_max_encumbrance() ){
          tell_object(ob,"你的负荷过重了！\n");
          return 0;
        }
        if(userp(ob)&&sizeof(all_inventory(ob))>=30){
          tell_object(ob,"你身上的东西太多了！\n");
          return 0;
        }

        // Move the object and update encumbrance
        if( environment() )     environment()->add_encumbrance( - weight());
        //----: Puff add these for fix the big bug which can cause crash
        flag1 = 0;
        flag2 = 0;
        flag3 = 0;
                                                //move ob3 from env1 to env2
        if( ob3 = this_object() )
                if( ob3->is_character() && !living(ob3) )
                {
                        type3 = ob3->query("disable_type");
                        flag3 = 1;
                        ob3->enable_player();
                }
        if( env1 = environment(ob3) )
                if( env1->is_character() && !living(env1) )
                {
                        type1 = env1->query("disable_type");
                        flag1 = 1;
                        env1->enable_player();
                }
        if( env2 = ob )
                if( env2->is_character() && !living(env2) )
                {
                        type2 = env2->query("disable_type");
                        flag2 = 1;
                        env2->enable_player();
                }
        //-------- at 97/12/1 ---end1--------

        move_object(ob);

        //-------- Puff add these for fix the big bug which can cause crash
        if( flag1 )
                env1->disable_player(type1);
        if( flag2 )
                env2->disable_player(type2);
        if( flag3 )
                ob3->disable_player(type3);
        //-------- at 97/12/1 -----end2------

        ob->add_encumbrance(weight());

        // If we are players, try look where we are.
        if( interactive(this_object())          // are we linkdead?
        &&      living(this_object())                   // are we still concious?
        &&      !silently ) {
                if( query("env/brief") ){

                env = environment();
			str = env->query("short");
            if (!stringp(str)) str = "";
			if( mapp(exits = env->query("exits")) ) {
				dirs = sort_array(keys(exits), 1);
				for(i=0; i<sizeof(dirs); i++)
					if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
						dirs[i] = 0;
				dirs -= ({ 0 });
				if (sizeof(dirs)) str += " - " + BOLD + implode(dirs, "、") + NOR;
			}
			str += "\n";
			inv = all_inventory(env);
		      if (NATURE_D->is_look_night(this_object(),env))
			for(i=0; i<sizeof(inv); i++) {
				if( inv[i]==this_object() ) continue;
				if( this_object()->visible(inv[i])&&inv[i]->is_character() )
				        str += "一个朦胧的身影，看不清楚是谁\n";
				else str += "一团模模糊糊的东西\n";
			}
		else for(i=0; i<sizeof(inv); i++) {
				if( inv[i]==this_object() ) continue;
				if( this_object()->visible(inv[i]) ) str += "  " + inv[i]->short() + "\n";
			}
			tell_object(this_object(), str);}
                else
                        command("look");
        }

   if (!silently && query("rumor") && userp(ob)) {
   	        set("no_sell",1);
		str = ob->name(1);
		if (query("rumor") > 0) {
			str += "弄到了一"
				+ query("unit") + query("name");
			set("rumor", -1);
		} else {
			add("rumor", 1);
			if (where->query("short"))
				str += "在" + where->query("short") +
					"捡到了一" + query("unit") + query("name");
			else
				str += "从" + where->name(1) +
					"处得到了一" + query("unit") + query("name");
		}
		CHANNEL_D->do_channel(this_object(), "rumor", str + "。");
	}

	//如果默认NPC没有衣服和鞋子，则自动加上。 add by yanyan
	if(this_object()->is_character()&&
		this_object()->query("race")=="人类"&&
		!userp(this_object())&&
		!query("need_equip")&&
		(!query_temp("armor/cloth")||!query_temp("armor/boots"))
		){
		set("need_equip",1);
		get_cloth(this_object());
	}
        return 1;
}

void remove(string euid)
{
        object default_ob;

        if( !previous_object()
        ||      base_name(previous_object()) != SIMUL_EFUN_OB )
                error("move: remove() can only be called by destruct() simul efun.\n");

        if( userp(this_object()) && euid!=ROOT_UID ) {
                log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
                        euid, this_object()->query("id"), ctime(time())));
                error("你(" + euid + ")不能摧毁其他的使用者。\n");
        } else if( this_object()->query("equipped")) {
                if(     !this_object()->unequip() )
                        log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
        }

        // We only care about our own weight here, since remove() is called once
        // on each destruct(), so our inventory (encumbrance) will be counted as
        // well.
        if( environment() )     environment()->add_encumbrance( - weight );
        if( default_ob = this_object()->query_default_object() )
                default_ob->add("no_clean_up", -1);
}

int move_or_destruct( object dest )
{
        if( userp(this_object()) ) {
                tell_object(this_object(), "一阵时空的扭曲将你传送到另一个地方....\n");
                move(VOID_OB);
   }
}

void get_cloth(object user)
{
	object cloth,shoe;
   reset_eval_cost();

	if (user->query("class")=="bonze")
	{
		if (user->query("gender")=="女性"){
			cloth = new("/obj/cloth/ni-cloth.c");
			shoe = new("/obj/cloth/ni-xie.c");
		}else{
			cloth = new("/obj/cloth/seng-cloth.c");
			shoe = new("/obj/cloth/seng-xie.c");
		}
	}else{
		if (user->query("class")=="taoist"){
			if ( user->query("gender")=="女性"){
				cloth = new("/obj/cloth/daogu-cloth.c");
				shoe = new("/obj/cloth/dao-xie.c");
			}else{
				cloth = new("/obj/cloth/dao-cloth.c");
				shoe = new("/obj/cloth/dao-xie.c");
			}
		}else{
			if (user->query("family")){
				if ( user->query("gender")=="女性"){
					cloth = new("/obj/cloth/woman"+user->query("class"));
					shoe = new("/obj/cloth/female-shoe.c");
				}else{
					cloth = new("/obj/cloth/man"+user->query("class"));
					shoe = new("/obj/cloth/male-shoe.c");
				}
			}else{
				if ( user->query("gender")=="女性"){
					shoe = new("/obj/cloth/female-shoe.c");
					switch (1+random(8)){
		case 1: cloth = new("/obj/cloth/female1-cloth.c");break;
		case 2: cloth = new("/obj/cloth/female2-cloth.c");break;
		case 3: cloth = new("/obj/cloth/female3-cloth.c");break;
		case 4: cloth = new("/obj/cloth/female4-cloth.c");break;
		case 5: cloth = new("/obj/cloth/female5-cloth.c");break;
		case 6: cloth = new("/obj/cloth/female6-cloth.c");break;
		case 7: cloth = new("/obj/cloth/female7-cloth.c");break;
		default: cloth = new("/obj/cloth/female8-cloth.c");
					}
				}else{
					shoe = new("/obj/cloth/male-shoe.c");
					switch (1+random(8)){
		case 1: cloth = new("/obj/cloth/male1-cloth.c");break;
		case 2: cloth = new("/obj/cloth/male2-cloth.c");break;
		case 3: cloth = new("/obj/cloth/male3-cloth.c");break;
		case 4: cloth = new("/obj/cloth/male4-cloth.c");break;
		case 5: cloth = new("/obj/cloth/male5-cloth.c");break;
		case 6: cloth = new("/obj/cloth/male6-cloth.c");break;
		case 7: cloth = new("/obj/cloth/male7-cloth.c");break;
		default: cloth = new("/obj/cloth/male8-cloth.c");
					}
				}
			}
		}
	}

	if(objectp(shoe)&&shoe->move(user)){
		if(!shoe->wear())
			destruct(shoe);
	}
	if(objectp(cloth)&&cloth->move(user)){
	 	if(!cloth->wear())
	   		destruct(cloth);;
	}
}
