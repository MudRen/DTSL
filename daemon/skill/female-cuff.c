/*
Ů��NPC��ʹ�õ�ȭ�����������Ϊĳ��NPC��ƶ��ص��书��
����ͨ����Ů�ȣ�����ʹ�����ȭ����
*/

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$Nٻ��һ����������ȭ��$n��$l����ȥ��",
        "apply_factor": 5,
        "name": "��",
       "damage_type": "����"
]),

([  "action": "$N��������һ�ˣ��������˫ȭ�͵س�$n��$l����ȥ��",
        "apply_factor": 5,
        "name": "��",
        "damage_type": "����"
]),

([      "action": "$N����Ծ��˫��һɨ������һ����������ȭ�͵س�$n��$l��������",
        "apply_factor": 5,
        "name": "��",
        "damage_type": "����"
]),

([  "action": "$N��ȭһ�񣬵���$n�Ľ�����ͬʱ��ȭ��$n��$l��������ȥ��",
        "apply_factor": 5,
        "name": "��",
        "damage_type": "����"
]),

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
	return "hand";
}

string query_base()
{
	return "cuff";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

