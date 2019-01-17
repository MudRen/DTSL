
#include <ansi.h>
#include <condition.h>
#include <job_money.h>
inherit F_CLEAN_UP;

int update_condition(object me, int times)
{
   if(times<=0){   
  if(!me->query_temp("job/rong_job"))
  return 0;
  call_out("killer_come",1,me);
  return 0;}
   me->apply_condition("rongsx",times-1);
   return CND_CONTINUE;
}

void killer_come(object ob)
{
  object killer,letter;
  string kill_msg;
  if(!objectp(ob)){
  remove_call_out("killer_come");return;}
  kill_msg="$N��$n�ȵ����Һ��ٷ����ǳ�У����Ϊ�����£���������\n";
  killer=new("/d/job/songwupin/killer");
  ob->start_busy(1);
  message_vision(HIB"$NͻȻ����һ����紵����"NOR,ob);
  copy_object(killer,ob);
  killer->set_name("ɱ��",({"killer"}));
  killer->set("nickname",HIR"��Ѫ����"NOR);
  killer->delete("family");
  killer->delete("nickname");
  killer->delete("shili");
  killer->set("combat_exp",ob->query("combat_exp")*3/2);
  killer->move(environment(ob));
  message_vision(kill_msg,killer,ob);
  killer->set_leader(ob);
  killer->kill_ob(ob);
  remove_call_out("killer_come");return;
}
