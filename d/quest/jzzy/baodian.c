
inherit ROOM;

void create()
{
	set("short", "�޺���");
	set("long", @LONG
�����������У��������飬��������ʮ�����������Ծ�춵��ĵ�
ǧ�ֹ�����Ϊ��Ŀ����������ׯ�ϣ�����ÿֻ�ֵ���״�����ַ�������
��ͬ������������ͨ��󣬷����ޱߵĸо�������޺��������ܣ�����
����������γ��ݺ���ͨ�������
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"out":"/d/chengdu/dadian",
	]));
	set("objects",([
	  __DIR__"obj/luohan":1,
	  ]));
        
        set("killer_reward",1);
	setup();
	
}

void killer_reward(object killer,object victim)
{
  if(!killer||!victim)
  return;
  if(!userp(killer)||!userp(victim))
  return;
  if(!killer->query_temp("dtsl_quest_jzzy_action1"))
  return;
  if(victim->query("combat_exp")<=killer->query("combat_exp"))
  return;
  if(victim->query("vocation")!="ɱ��")
  return;
  
  tell_object(killer,"��վ���޺���ǰ�����������������µ������У�\n"+
  "�Ǹо�ʵ���κ��������������һ��\n");
  
  killer->delete_temp("dtsl_quest_jzzy_action1");
  killer->set_temp("dtsl_quest_jzzy_action2",1);
  
  return;
}