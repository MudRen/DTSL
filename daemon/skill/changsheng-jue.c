//������

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{             
    if((int)me->query_skill("changsheng-jue",1) > 400 )
        return notify_fail("������ѧϰ�Ѿ��޷�����ӱ���������ˣ��Լ�ȥ������ɡ� \n");
        return 1;
}


int practice_skill(object me)
{
          return notify_fail("������ֻ��ͨ�����������!\n");
}


string query_type()
{
	return "force_skill";
}

string query_base()
{
	return "force";
}

int query_exercise(object me)
{

  if(!me->query("force_quest/csj_ok"))
   return 10;
  else
   return 100;
}

int query_respirate(object me) 
{
if(!me->query("force_quest/csj_ok"))
   return 10;
  else
   return 100;
}

string sub_exercise(object me)
{
      if(me->query("force_quest/csj2"))
      return HIB"$N"+HIB+"�����й�����ͣ��"+BLINK+HIW+"�����߶�"+NOR+HIB+"���о�����֮���鲼ȫ��\n"NOR;
      else
      return HIW"$N"+HIW+"��������������£�����"+BLINK+MAG+"�����ؾ�"+NOR+HIW+",��˿������\n"NOR;
      	
	
}

string sub_respirate(object me)
{
      if(me->query("force_quest/csj2"))
      return HIB"$N"+HIB+"�����й�����ͣ��"+BLINK+HIW+"�����߶�"+NOR+HIB+"���о�����֮���鲼ȫ��\n"NOR;
      else
      return HIW"$N"+HIW+"��������������£�����"+BLINK+MAG+"�����ؾ�"+NOR+HIW+",��˿������\n"NOR;
}

string *query_exert() 
{
	return ({"wu","luoxuan"});
}

