
#include <ansi.h>
#include <condition.h>
#include <job_money.h>

inherit F_CLEAN_UP;

int update_condition(object me, int times)
{
   
   object killer;
   object killer2;
   
   if(!me->query_temp("guanchai_yunyan"))
    return 0;
   if(!objectp(me->query_temp("track")))
    return 0;
   if(times<=0){
   	tell_object(me,HIB"\nͻȻһ����紵�˹�����\n\n"NOR);
   	killer=new("/d/job/yunyanjob/killer");
   	killer->set("combat_exp",me->query("combat_exp"));
   	copy_hp_item(me,killer,"kee");
        copy_hp_item(me,killer,"sen");
        copy_hp_item(me,killer,"gin");
        killer->set("max_force",me->query("max_force"));
        killer->set("force",me->query("max_force"));
        set_all_skill(killer,me->query("max_pot")-130);
        if(me->query("combat_exp")>=500000){
        killer2=new("/d/job/yunyanjob/killer");
        killer2->set("combat_exp",me->query("combat_exp"));
   	copy_hp_item(me,killer2,"kee");
        copy_hp_item(me,killer2,"sen");
        copy_hp_item(me,killer2,"gin");
        killer2->set("max_force",me->query("max_force"));
        killer2->set("force",me->query("max_force"));
        set_all_skill(killer2,me->query("max_pot")-130);
       killer2->move(environment(me));}
        killer->move(environment(me));
        killer->kill_ob(me);
        killer->set("target_id",me->query("id"));
        if(killer2){
        killer2->set("target_id",me->query("id"));
        killer2->kill_ob(me);}
   	return 0;}
   	   
      me->apply_condition("yunyan_job_killer", times - 1);
  return CND_CONTINUE;
}
