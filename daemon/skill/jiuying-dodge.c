//��ӥ����

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$nһ����Ц��������𣬾���������������ܹ�$N�Ĺ���������һ������Ͷȥ��"
]),
([      "action" : "$N����$nʱ��$n����Ҫ���ӭս����֪������������ܿ��������Ǻ���ؼ�ĳһ�ֵ�\n"+
                   "��ĸо���" 
]),
([      "action" : "$n�������������ձܿ�$N�Ĺ�������б�ɶ�����Զ��Ͷȥ����̬�������㡣" 
]),
([      "action" : "$n���񻯳�һ��û�����������̣���������������Ʈ�ƻζ���ÿһ�̶����ϱ任λ�á�"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
       if(me->query_skill("dodge",1)<60)
       return notify_fail("��Ļ����Ṧ��Ϊ�������޷�������ӥ���衣\n");

	   return 1;
}



int practice_skill(object me)
{
     
	
	return 1;
}

string query_type()
{
	return "dodge";
}
string query_base()
{
	return "dodge";
}

string *query_perform()
{
   return ({"tianxiang"});
}

int query_dodge(object me)
{
	return 120;
}