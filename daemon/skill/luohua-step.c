//�仨���衣
//�������Ṧ��

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n�������֮�䣬�����ڻ����й����ʻ�һ�㣬����һ�С���Ȼ���ݡ����ɵض㿪$N�Ľ�����"
]),
([      "action" : "$n�����Ȼ������һ�㣬�������Ļ���ƮȻ���һ�����㿪��$N�Ľ���������һ�С����𻨷ɡ���"
]),
([      "action" : "$n���β���ͻȻ��ÿ����������������ڻ����з��裬һ�С��ʵ����¡��ܿ���$N�Ĺ�����" 
]),
([      "action" : "��Ȼ$N�Ĺ��Ʋ�С������$nȴ�ǲ��Ų�æ����������ڻ����еĺ�����һ�С����軨�ԡ�������˿�����" 
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
    
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

int query_dodge(object me)
{
	return 80;
}