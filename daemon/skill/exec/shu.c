
#include <ansi.h>
inherit SSERVER;
/*�ķ�ִ�к���
  ͳһ���� /daemon/skill/exec/ �¡�
*/
int execute(object me,object victim)
{
  
  int max_points,cost_force,lev;
  string msg;
  int time,add_time;
  
  if(victim!=me)
  return notify_fail("�㲻�ܶԱ���ʹ������ķ���\n");
    
  if(me->query("force")<=0)
  return notify_fail("����������㣡\n");
  
  max_points=me->query("max_apply_points")-me->query("apply_points");
  if(max_points<=0)
  return notify_fail("���������Ƹ��ǣ��������ķ��߼ӡ�\n");
  if(time()-me->query_temp("execute_busy")<10)
  return notify_fail("�㲻������ʹ���ķ���\n");
  
  lev=me->query_skill("yijian-shu",1);
  cost_force=max_points*(100+lev)/lev;
  if(cost_force<=0)
   cost_force=max_points;
  
  if(me->query("force")<cost_force){
    cost_force=me->query("force");
    max_points=max_points/2;
  }
  
  msg=HIG"$N"+HIG+"����΢���£�ֻ��˫Ŀ���������â���������ˣ�\n"NOR;
  message_vision(msg,me);
  
  //�����������ƣ�
  
  add_time=10;
  me->set_temp("add_apply_points",max_points/add_time);
  me->set_temp("reduce_force",cost_force/add_time);
  me->set_temp("add_apply_points_yushu",max_points%add_time);
  me->set_temp("reduce_force_yushu",cost_force%add_time);
  me->set_temp("add_apply_points_times",add_time);
  
  //�ķ�����ʱ�䣺
  time=9*lev/(lev+100);
  if(time<=0)
  time=1;
  me->set("apply_points_last",time);
  me->set("apply_points_reduce",(max_points+me->query("apply_points"))/6);
  me->set("apply_points_last_times",time);
  
  //�ķ����˺������ʱ�䣺
  
  me->set("full_points_last",1);
  me->set_temp("execute_busy",time());
  
  return 1;
}