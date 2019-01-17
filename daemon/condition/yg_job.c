
#include <ansi.h>
#include <condition.h>
#include <job_money.h>

inherit F_CLEAN_UP;

int update_condition(object me, int times)
{
   
   object killer;
   object killer2;
   object letter;
   
   if(!me->query_temp("zhu_sx"))
    return 0;
   
   if(times<=0){
   	tell_object(me,HIB"\n�ƺ����˴���ı���Ϯ����\n\n"NOR);
   	killer=new("/d/job/ygsongxin/killer");
   	if(objectp(letter=present("letter",me)))
	  if(letter->query("owner")==me){	
	letter->move(killer);
	tell_object(me,HIW"\n���������������!\n"NOR);}
	
	killer->set("combat_exp",me->query("combat_exp"));
	set_all_skill(killer,me->query("max_pot")-110);
	copy_hp_item(me,killer,"gin");
	copy_hp_item(me,killer,"kee");
	copy_hp_item(me,killer,"sen");
	killer->set("max_force",me->query("max_force"));
	killer->set("force",me->query("max_force"));
	killer->set_temp("apply/armor",50+random(50));
	
	killer->move(environment(me));
	message_vision("\n$N������:а��֮��������!\n",killer);
	killer->kill_ob(me);
        killer->set("target_id",me->query("id"));
        if(me->query("combat_exp")>=500000){
          killer2=new("/d/job/ygsongxin/killer");
          copy_object(killer2,killer);
          killer2->move(environment(me));
          killer2->kill_ob(me);}	
   	return 0;}
   	   
      me->apply_condition("yg_job", times - 1);
   if( times < 1 ) return 0;
   return CND_CONTINUE;
}
