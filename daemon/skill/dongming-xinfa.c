//�����ķ���

inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
    return 1;
}

string *query_execute()
{
   return ({"xiongyong"});
}

string help_action()
{
write(@LONG
    �����ķ�
��������������������������������������������
    execute:
    execute xiongyong
��������������������������������������������
        
LONG);
return "\n";
}