//��������


inherit SKILL;

string query_type()
{
  return "knowledge";
}

int valid_learn(object me)
{
   if(me->query_skill("poison",1)>=me->query("int")*6)
	return notify_fail("���޷���ͨ��ѧ����ߴ˼����ˣ����ǵ�ʵ����ȥ��߰ɣ�\n");
  return 1;
}