//��ħ����.

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n���л�����ȣ����Ӱһ�㣬�����һΣ�һ�С���Ӱ�������㿪��$N�Ĺ�����" 
]),
([      "action" : "$n��̤���������к������֣�����һ�С�ħӰ���Ρ�������ض㿪��$N�Ĺ�����"
]),
([      "action" : "$n΢΢һЦ����̬����֮����һ�С�ħЦ��硹����ض㿪��$N�Ĺ���!" 
]),
([      "action" : "$n���Ų�æ�����к�Ȼ���Խ�����������ɵ��ؼ�����ħ���졹�����ɵĶ㿪��$N�Ĺ�����"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
       if(me->query_skill("dodge",1)<10)
       return notify_fail("��Ļ����Ṧ��Ϊ�������޷�������ħ���١�\n");

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
   return ({"modun"});
}

int query_dodge(object me)
{
	return 80;
}