//�����м�.

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�����������$n��$l",
        "apply_factor":2,
        "name":"����ȭ��",
        "damage_type": "����"
]),
([
 "action":"$N���������$n��$l��ȥ!",
 "apply_factor":2,
 "name":"����ȭ��",
 "damage_type": "����"
]),
([
 "action":"$N��������,һ������$n��$l!",
 "apply_factor":2,
 "name":"����ȭ��",
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

int skill_damage(object me,object victim)
{
	return 20;
}