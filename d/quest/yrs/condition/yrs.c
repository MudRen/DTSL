
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object ob, int times)
{
  
   if(!ob->query_temp("apply/yrs"))
   return 0;
   if(times<=20){
   	
   	ob->delete_temp("apply/name");
        ob->delete_temp("apply/id");
        ob->delete_temp("apply/short");
        ob->delete_temp("apply/long");
        tell_object(ob,YEL"����Ѿ�ʧȥЧ���ˣ�\n"NOR);}
   else if(times<40){
   	ob->delete_temp("apply/short");
        ob->delete_temp("apply/long");
        tell_object(ob,YEL"��߿�ҪʧȥЧ���ˣ�\n"NOR);}
   	
   
   ob->apply_condition("yrs", times - 1);
   if( times < 1 ) return 0;
   return CND_CONTINUE;
}
