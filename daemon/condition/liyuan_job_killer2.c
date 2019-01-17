
#include <ansi.h>
#include <condition.h>
#include <job_money.h>

inherit F_CLEAN_UP;

string *killer_name=({"��","Ǯ","��","��","��","��","֣","��"});
string *killer_id=({"һ","��","��","��","��","��","��","��"});

int update_condition(object ob, int times)
{
   object target;
   string name;
   
   if(ob->query_temp("liyuan_job/step")!=13)
  return 0;
   
   if(times<=0){
   	tell_object(ob,HIB"\n���Ȼ����һ�����Ϯ����\n\n"NOR);
   	name=killer_name[random(sizeof(killer_name))]+
       killer_id[random(sizeof(killer_id))];
       
       target=new("/d/job/liyuanjob/killer5");
  target->set("combat_exp",ob->query("combat_exp"));
  set_all_skill(target,ob->query("max_pot")-70);
  copy_hp_item(ob,target,"gin");
  copy_hp_item(ob,target,"kee");
  copy_hp_item(ob,target,"sen");
  target->set("max_force",ob->query("max_force"));
  target->set("force",ob->query("max_force"));
  target->set("target_id",ob->query("id"));
  target->set("name",name);
  target->set("target_id",ob->query("id"));
  target->move(environment(ob));
  tell_object(ob,"��Ȼ����һ����������!!\n");
  message_vision("\n$N��$n�е������������㵹ù���������������Կ������С����\n",
                 target,ob);
  target->kill_ob(ob);
       	
   	return 0;}
   	   
      ob->apply_condition("liyuan_job_killer2", times - 1);
   if( times < 1 ) return 0;
   return CND_CONTINUE;
}
