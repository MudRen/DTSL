//����ӡ��


inherit SKILL;
#include <ansi.h>

string *actions=({
HIB"$N"+HIB+"������ͬ���Ȱ�ػζ��˼��£�������һ��㿪��$n"+HIB+"�Ĺ�����\n"NOR,
HIB"$N"+HIB+"����΢΢�ζ����Ų�������ת���㿪��$n"+HIB+"�Ĺ�����\n"NOR,
HIB"$N"+HIB+"��̤��������һ�������ؿ��ݽ����磬������$n"+HIB+"�Ĺ�����\n"NOR,
HIB"$N"+HIB+"����һ��ĵ����γ�һ����Ӱ��ǽ�ڣ�������$n"+HIB+"�Ĺ�����\n"NOR,
HIB"$N"+HIB+"������Ϣ������Ĭ���ӡ����ֻ��һ��������ס��$n"+HIB+"�Ĺ�����\n"NOR,
});
string query_type()
{
  return "knowledge";
}

int valid_learn(object me)
{
        if((int)me->query_skill("busi-yin",1) > 400 )
            return notify_fail("������ѧϰ�Ѿ��޷�����ӱ���������ˣ��Լ�ȥ������ɡ� \n");
  
  if(!me->query("execute_quest/busiyin",1))
   return notify_fail("�������޷���᲻��ӡ�İ��أ�\n");
  
  return 1;
  
}

string *query_execute()
{
   return ({"yin","shengsi"});
}

