//ħ������.
//�м��书��
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N˫�Ʊ任���û������������״��һ�С��������֡���$n��$l����ȥ��",
    "apply_factor": 2,
    "name" : "��������",  
    "damage_type":"����",
  ]),
 ([ "action":"$N˫�ƹ�ע�������ͺ�һ����ֻ��һ��������$n��ȥ������һ�С�ħ�����֡���",
    "apply_factor": 5,
    "name" : "ħ������",
    "damage_type":"����",
  ]),
  ([ "action":"$N�߸�����˫�ƻû�������״��һ�С��������桹��$n��$l����ȥ��",
    "apply_factor": 6,
    "name" : "��������",
    "damage_type":"����",
  ]),
  ([ "action":"$N��������ͻȻһ��Ϊ�����仯���죬һ�С�ħ��˫�ɡ���$n��������·ץȥ��",
    "apply_factor": 8,
    "name" : "ħ��˫��",
    "damage_type":"ץ��",
  ])});  

string *parry_weapon=({

"$Nһ�Ƴ�$n��$v��ȥ��ƾ��ǿ�����������$n��$v��\n",
"$N��������ͻȻһ��Ϊ���������������ң���ס��$n�Ľ�����\n",
"$N��߸�����˫�ƻû�������״����ס��$n�Ľ�����\n",
"$N˫�Ʊ任���û������������״������$n��$v��\n"

});

string *parry_hand=({

"$N����������ӭ��$n�Ľ�����ֻ������һ����˫�����˺󼸲���\n",
"$N�������ι��죬$n���Ʋ��ã���æ���˿�����\n",
"$N����Ź֣��������λ����ݳ������û�����$n�Ľ�����\n",
"$N��$n���ƶ���һ��ֻ������һ����˫�����˺󼸲���\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

} 

int valid_learn(object me)  
{
    
   
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰħ��������\n");
    
     return 1;    


}

int practice_skill(object me)  
{
 
 if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ�����ϰħ��������\n");
            
 return 1;  


}


mapping query_action(object me,object weapon)
{
   
return action[random(sizeof(action))];  
 
}

mapping *query_all_action(object me)
{
return action;	
}

string *query_perform()
{
	return ({"feilian"}); 
}

string query_type()    
{                   
	return "hand";
}
string query_base()  
{
	return "strike";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
int skill_damage(object me,object victim)
{
  
  return 120;
}