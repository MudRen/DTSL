
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
   if(me->query("jiali")<50){
   me->receive_wound("gin",20+random(10));}
   if(!living(me)){
   me->set("last_damage_msg",me->name()+"被蛇毒毒死了。\n");
   return 0;}
   tell_object(me,HIB"你中的蛇毒发作了！\n" NOR );
   me->start_busy(random(1));
   if( duration < 1 ){ 
   return 0;}
   me->apply_condition("snake_poison", duration - 1);
   return CND_CONTINUE;
}
