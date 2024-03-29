// go.c
// // #pragma optimize all
//last modify by mudadm
//last modify by yanyan, 2001/,for guanchai_yunyan job.
#include <ansi.h>
#include <localtime.h>

#define TIME_TICK1 ((time())*60)

inherit F_CLEAN_UP;
mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"东",
	"west":			"西",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
        "enter":                "里",
	"up":			"上",
	"down":			"下",
	"out":			"外",
]);

void create() { seteuid(getuid()); }
int drop_things(object me)
{
	int i,max;
	object *inv;
	object env;

	env = environment(me);
	max = me->query_max_encumbrance();
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++){
		if(inv[i]->query("equipped")) continue;
		if(inv[i]->query("owner")) continue;
		if(inv[i]->query("no_get")) continue;
		if(inv[i]->query("no_drop")) continue;
		if(inv[i]->query("no_give")) continue;
		if(random(max) < inv[i]->weight())
		{
			tell_object(env,"在慌乱中，");
			me->ccommand("drop "+inv[i]->query("id"));
		}

	}

}
int check_flee(object me, string arg)
{
   mapping 	my, your;
   object 	*enemy;object track;
   int		fp, bp, i;

   i = me->query("combat_exp");
   if ( (random(i) < 300) && userp(me) ) return 1;
   enemy = me->query_enemy();
   for(i=0; i<sizeof(enemy); i++) {
      if( objectp(enemy[i]) && environment(enemy[i])== environment(me) && living(enemy[i])) {
         fp = me->query_dex();
         if(fp<1) fp = 1;
         bp = enemy[i]->query_dex();
         if(bp<1) bp = 1;
         if(random(fp*2+bp) > fp*2||!userp(me)) {
            message_vision(YEL "$N向" + arg + "逃去！\n" NOR, me);
            message_vision(RED "$N身影一闪，挡在了$n的面前！\n" NOR, enemy[i], me);
            return 0;
         }
      }
   }
   return 1;
}

int is_night(object me,object env)
{

	return NATURE_D->is_night(me,env);

}


int main(object me, string arg)
{
        string dest, mout, min, dir,dir1,blk,ridemsg,str,str1;
        object env, obj, blocker,ridee;object track;
        int count = 0, my_dex, i,n,i_env,i_obj,date;
		mapping exit;
		mapping block;
        mapping gt;
        mixed *local;
        mixed old_target;
        n=NATURE_D->night();



	if( !arg ) return notify_fail("你要往哪个方向走？\n");

	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");

	if(me->query_temp("no_move")){
	   if(stringp(me->query_temp("no_move")))
	    return notify_fail(me->query_temp("no_move"));
	   else
	   return notify_fail("你无法走动！\n");
        }
	if( me->is_busy() )
		return notify_fail("你现在忙得很，不能移动。\n");

        if( me->query("sen") < 3 && !me->is_ghost())
                return notify_fail("你现在累得根本就走不动路了。\n");

        if(me->query("food")<=0||me->query("water")<=0)
           if(time()-me->query_temp("no_food_busy")>40)
             if(userp(me)){
         me->set_temp("no_food_busy",time());
         me->start_busy(2);
         return notify_fail("你饥渴无比，根本走不动路了！\n");}

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else
			return 0;
	}

/*      if( mapp(block = env->query("blocks"))&& blk=block[arg]) {
        if( objectp(blocker = present(blk, env)) &&  living(blocker))
                return notify_fail("这个方向的路被"+ blocker->name() + "挡住了 。\n");
*/

    if ( old_target = me->query_temp("guardfor") )
    {
    	if(objectp(old_target))
    	{
    		if( living(old_target) )
               {
                    tell_object(me,"你放弃保护"+old_target->name()+"。\n");
                    me->delete_temp("guardfor");
             }
		    else
              {
                    tell_object(me,"你不再理会"+old_target->name()+"，径直走了。\n");
                    me->delete_temp("guardfor");
              }
          }
    }

	dest = exit[arg];

        if( !(obj = load_object(dest)) )
           return notify_fail("你要去的区域还没有连通。\n");

	if( !(obj = find_object(dest)) )
		return notify_fail("无法移动。\n");


	if( !env->valid_leave(me, arg) ) return 0;
    if( env->valid_leave(me, arg)>1) return 1;
	//if(obj->query("makelove_room"))
	// return notify_fail("有一对夫妇在那面，你还是先不要去了！\n");

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

        if (ridee = me->ride())
          ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
        else
          ridemsg = "";

	n=NATURE_D->night();
	i_env=(int)env->query("outdoors");
	i_obj=(int)obj->query("outdoors");

	if( me->is_fighting() )
	{
        if(check_flee(me, dir) == 0) {
        return notify_fail("你被挡了回来。\n");
		}
        drop_things(me);
		if(objectp(track=me->query_temp("track")))
		{
			str1=ridemsg+"赶着"+track->name()+"往"+dir+"落荒而逃了。\n";
			str=ridemsg+"赶着"+track->name()+"跌跌撞撞地跑了过来，模样有些狼狈。\n";
		}
		else
		{str1 = ridemsg + "往" + dir + "落荒而逃了。\n";
        str = ridemsg + "跌跌撞撞地跑了过来，模样有些狼狈。\n";}
    }
	else if ( ridee = me->ride() ){
		str1 = ridemsg+ "往" + dir + "疾驰而去。\n";
        str = ridemsg+ "疾驰而来。\n";
    }
    else if(objectp(track=me->query_temp("track"))){
		str1=ridemsg+"赶着"+track->name()+"往"+dir+"离开了。\n";
		str=ridemsg+"赶着"+track->name()+"走了过来。\n";
	}else if(me->query("pker")){
		str  = "慌慌张张地从"+env->query("short")+"走了过来。\n";
		str1 ="往" + dir + "慌慌张张地离开了。\n";
	}
	else{
		str  = "从"+env->query("short")+"走了过来。\n";
		str1 ="往" + dir + "离开了。\n";
	}

	if(is_night(me,env)){

		if(me->query("gender") == "女性"){
			mout = "一条倩影" + str1;
		}
		else{
			mout = "一条黑影" + str1;
		}
	}
	else{
		mout = str1;
	}
	if(is_night(me,obj)){

		if(me->query("gender") == "女性"){
			min =  "一条倩影" + str;
		}
		else{
			min  = "一条黑影" + str;
		}
	}
	else{
		min = str;
	}


	if (!userp(me) && obj->query("NONPC"))
			return notify_fail("你不可去那里。\n");
	else if(obj->valid_enter(me))
			return notify_fail("你不可去别人的私宅。\n");

	if(!is_night(me,env))
    	message( "vision", me->name() + mout, environment(me), ({me}) );
    else
    	message( "vision", mout, environment(me), ({me}) );

	if(me->move(obj) ) {
		me->remove_all_enemy();
		if(!is_night(me,obj))
			message( "vision", me->name() + min, environment(me), ({me}) );
		else
			message( "vision", min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		if(env != obj)
			all_inventory(env)->follow_me(me, arg);
		if(track){
			me->receive_damage("sen",5+random(5));
			track->move(obj);
		}  //add by yanyan
		if (objectp(track))
			tell_object (me,"你"+min);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>

让你往指定的方向移动。

HELP
    );
    return 1;
}
