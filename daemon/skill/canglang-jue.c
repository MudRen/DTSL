//���Ǿ���ͻ�����ķ���


inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
    if((int)me->query_skill("canglang-jue",1) > 400 )
        return notify_fail("������ѧϰ�Ѿ��޷�����ӱ���������ˣ��Լ�ȥ������ɡ� \n");
    return 1;
}

string *query_execute()
{
   return ({"xiao"});
}

string help_action()
{
write(@LONG
    ���Ǿ�
��������������������������������������������
    execute:
    execute xiao
��������������������������������������������
        
LONG);
return "\n";
}
