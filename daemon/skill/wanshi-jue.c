//��ʯ����


inherit SKILL;
#include <ansi.h>

string query_type()
{
  return "knowledge";
}

int valid_learn(object me)
{
  
  if(!me->query("execute_quest/wanshijue",1)&&
     me->query("vocation")!="ɱ��")
   return notify_fail("�������޷������ʯ���İ��أ�\n");
  
  return 1;
  
}

string *query_execute()
{
   return ({"huanmo","wuxing"});
}
