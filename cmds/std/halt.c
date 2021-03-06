
#include "/doc/help.h"
inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
   object ob;
   
   if( arg && wizardp(me) ) {
		ob = present(arg, environment(me));
		if( !ob ) return notify_fail("没有这个生物。\n");
		if( !ob->is_fighting() ) return notify_fail(ob->name()+"现在不忙。\n");
		ob->remove_all_enemy();
                message_vision("\n$N用巫师的神力停止了$n的战斗。\n", me, ob);
		return 1;
	}
    
    if(wizardp(me)&&me->is_fighting()){
      
       me->remove_all_killer();
       tell_object(me,"你用巫师的神力停止了战斗！\n");
       message_vision("\n$N向后一跃，跳出战圈不打了。\n",me);
       return 1;
       }
    
	if (!me->is_busy() && me->is_fighting()) {
	        
	        me->remove_all_enemy();
                message_vision("\n$N身行向后一跃，跳出战圈不打了。\n", me); 
		return 1;
	}
   if(!me->is_busy()){
    tell_object(me,"你现在不忙。\n");
    return 1;}
   
   me->interrupt_me();
   
   if(me->is_busy())
    tell_object(me,"你现在很忙，停不下来！\n");
   
   return 1;
}

int help(object me)
{
   write(@HELP
指令格式: halt

可以停止所有与你有关的战斗,打坐，吐纳。
HELP
   );
   return 1;
}
