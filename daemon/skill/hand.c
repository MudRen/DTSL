//�����м�.

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�����������$n",
        "dodge": 10,
        "force": 50,
		"damage":50,
        "parry" : -15,
        "damage_type": "����"
]),
([
 "action":"$Nһʽ[�ڻ�����]����$n������!",
 "dodge":15,
 "force":50,
 "parry":20,
 "damage_type": "����"
]),
([
 "action":"$N��������,һ������$n��ͷ��!",
 "dodge":15,
 "force":50,
 "parry":20,
 "damage_type": "����"
])


});





string query_skill_name(int level)
{
        
}

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
	return "base";
}

string perform_action_file(string action)
{
	return __DIR__"hand/"+action;
}