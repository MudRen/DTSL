
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int times)
{
   
   object card;
   
   if(!me->query_temp("guanchai_yunyan"))
    return 0;
   
   if(times<=0){
   	card=new("/d/xiangyang/obj/card");
   	card->move(me);
   	message_vision(YEL"�ٱ�����$Nһ�⹫����\n"NOR,me);
   	return 0;}
   	   
      me->apply_condition("yunyan_job", times - 1);
   if( times < 1 ) return 0;
   return CND_CONTINUE;
}
