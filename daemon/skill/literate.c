//����֪ʶ����
//�����ʶ�֣��Ĺ������ȡ�


inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
   if(me->query_skill("literate",1)>400
    &&!me->query_temp("mark/literate",1))
    return notify_fail("������㻹�ǵ���Ժѧϰ�ɣ�\n");
   
  return 1;
}

string perform_action_file(string action)
{
	return __DIR__"literate/"+action;
	
}