
#include <ansi.h>
#include <condition.h>
#include <job_money.h>

inherit F_CLEAN_UP;

int update_condition(object me, int times)
{
   
   object *t;
   object killer;
   object swap;
   int i;
   
   if(!me->query_temp("dtsl_job_cisha"))
    return 0;
   if(times>0)
   tell_room(environment(me),YEL"ֻ��Զ������̸Ц���������ƺ��������������ˡ�\n"NOR);
   
   if(times<=0){
   	
   	t=me->query_team();
   	if(sizeof(t)>0){
   	 swap=t[0];
   	 for(i=1;i<sizeof(t);i++)
   	  if(t[i]&&environment(t[i])==environment(me))
   	    if(t[i]->query("combat_exp")>swap->query("combat_exp"))
   	      swap=t[i];}
   	else swap=me;
   	killer=new("/d/job/cisha/killer");
   	set_all_skill(killer,swap->query("max_pot")-105);
   	killer->set("combat_exp",swap->query("combat_exp"));
   	killer->set("max_pot",swap->query("max_pot"));
   	killer->move("/d/job/cisha/chunyuan");
   	tell_room(environment(me),YEL"ֻ��¥�µ������������У�ȷʵ�����������ˣ�\n"NOR);
   	if(sizeof(t)>0){
   	 message_vision(HIG"ֻ��$Nһ����Х�������������Ѿ�����¥�£���λ�ϰ�����\n"NOR,me);
   	 tell_room("/d/job/cisha/chunyuan","ֻ��¥�����˺���һ�������������������ˣ�\n");
   	 for(i=0;i<sizeof(t);i++)
   	  if(t[i]&&living(t[i])){
   	    message_vision("ֻ�����һ����$N�ƴ���������\n",t[i]);
   	    killer->add_array("target_id",t[i]->query("id"));
   	    t[i]->move("/d/job/cisha/chunyuan");}
   	 message_vision(HIW"$N��$nŭĿ���ӣ�ԭ�������С�������������ͬ��һ���ϰɣ�\n"NOR,killer,me);
   	 killer->kill_ob(me);
   	 return 0;}
   	else{
   	message_vision(HIG"ֻ��$Nһ����Х��������������Ҫ���ܣ�\n"NOR,me);
   	 tell_room("/d/job/cisha/chunyuan","ֻ��¥�����˺���һ��������������һ���ˣ�\n");
   	message_vision(HIW"$N��$nŭĿ���ӣ�ԭ�������С�����������ɣ�\n"NOR,killer,me);
   	killer->set("target_id",me->query("id"));
   	me->move("/d/job/cisha/chunyuan");
   	killer->kill_ob(me);
   	return 0;}
   	}
   	   
      me->apply_condition("cisha_job", times - 1);
   if( times < 1 ) return 0;
   return CND_CONTINUE;
}
