//Ʈ�ν���.
//�м�-->�ռ��书��

inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N������������$n��֪���٣�ͻȻһ�С�����է�֡�����$n��$l����",
    "apply_factor": 2,
    "name" : "����է��", 
    "damage_type":"����",
  ]),
 ([ "action":"$N���е�$w�ķ�������������һƬ�������͵�һ�С����Ѷ��项����$n��$l����",
    "apply_factor": 5,
    "name" : "���Ѷ���",
    "damage_type":"����",
  ]),
  ([ "action":"$N����Ư��������Χס$n��ס��ת�����е�$wһ�С����ΰ˷���ͻȻ����$n��$l��",
    "apply_factor": 10,
    "name" : "���ΰ˷�",
    "damage_type":"����",
  ]),
  ([ "action":"$N���б��������ֻ�סͷ������������֮״�����е�$wһ�С��������Ρ�����$n��$l��",
    "apply_factor": 7,
    "name" : "��������",
    "damage_type":"����",
  ])});   

string *parry_weapon=({

"$N���е�$w������ĥ����������ʵʵ��$nֻ����������һ���޵׵����У���æ���˿�����\n",
"$N��߳һ��������һ��$w��ֻ��$w����һ�����������ߣ���ס��$n��$v��\n",
"$Nһ�����Ʋ����æ������н��Ż���ס��$nҲ���޿��κΣ�\n",
"$N��$wֱ��$n�����̴�ȥ��$n����֮�£�ֻ���ջ���$v��\n"

});

string *parry_hand=({

"$N��$w���糤���۾�����$n�������ȥ��$n����֮��ֻ�ú��˼�����\n",
"$Nһ�����е�$w��$w��������һ�㣬����������֮�䣬$n�Ľ���֮��Ҳ��Ϊ���У�\n",
"$N��Цһ�������е�$w�������������������赸�����������$n�Ľ�����\n",
"$N��$w����һ����������$n�Ľ�����\n"

});


string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

mapping query_action(object me,object weapon)
{
         return action[random(sizeof(action))];
 

}
mapping *query_all_action(object me)
{
return action;	
}

string query_type()    
{                      
	return "sword";
}
string query_base()  
{
	return "sword";
}

int valid_learn(object me)
{
	object weapon;
   if(!objectp(weapon=me->query_temp("weapon"))||
	  weapon->query("skill_type")!="sword")
			return notify_fail("�����޽�,���ѧϰƮ�ν�����\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
 
 return 1;  


}
string *query_perform()
{
	return ({"duomeng","zuimeng"}); 
}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}


int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/duomeng"))
  return 180;
  return 100;
}
