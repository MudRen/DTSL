//��ħ�ȷ���������Ժ�书��
//�м�-->�ռ��书��

inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����$n�����ƣ����Ų�æ��ʹ����ħ�ȷ��еġ������ࡹ�����е�$w����������Ӱ���ص�ˮй��ͨ��",
    "apply_factor": 2,
    "name" : "������", 
    "damage_type":"����",
  ]),
 ([ "action":"$N˫���������ŲȾŹ�����֮�ƣ��ζ����У�һ�С���ħ����������$n��$l��",
    "apply_factor": 5,
    "name" : "��ħ����", 
    "damage_type":"����",
  ]),
  ([ "action":"$N���к��ˣ����Ȼ��裬����һ��ǿ�磬һ�С������������д����س�$n��ȥ��",
    "apply_factor": 10,
    "name" : "������",
    "damage_type":"����",
  ]),
  ([ "action":"$N���һ��������$w������ת��ֻ��$w�д���һ��ǿ��������$n��$l����ȥ��",
    "apply_factor": 7,
    "name" : "���ޱ�",
    "damage_type":"����",
  ])});   
  
string *parry_weapon=({

"$Nһ���ͺȣ���$w��ס��$n��$v�����$n�˺��˼�����\n",
"$Nһ��$w�������һ��ԲȦ����$n��$v���˳�ȥ��\n",
"$Nһ��$w���Լ���Ч��������ס��$n��$v��\n",
"$N��$w���迪����$n��æ�˺�ʹ$v�޴����֣�\n"

});

string *parry_hand=({

"$N��׼���ᣬ����$wһ�ᣬǡ�÷�ס��$n�Ľ�����\n",
"$Nһ������$w���Թ����س�$n��ȥ��$n��æ������\n",
"$N����$wһ�ӣ����������Ѱ���Ž����Ļ��ᡣ\n",
"$N����$wһ�ᣬ���Ǽ򵥵���ʽ��ȴ��ס��$n��ȫ������֮����\n"

});



int valid_learn(object me)    
{
    object weapon;
    
    if(me->query("chanyuan_skill")!="fumo-zhangfa")
    return notify_fail("�㲻��ѧϰ������ܣ�\n");
    if((int)me->query("PKS",1)>=5)
    return notify_fail("��е��������أ������ټ���ѧϰ����ħ�ȷ����ˣ�\n");
	weapon=me->query_temp("weapon");
	if(!objectp(weapon))
		return notify_fail("�������ȣ����ѧϰ����ħ�ȷ�����\n");
	if((string)weapon->query("skill_type")!="staff")
		return notify_fail("��ʹ�õ��������ԣ�\n");
	return 1;    


}

int practice_skill(object me)  
{
   object weapon;
   weapon=me->query_temp("weapon");
   if(me->query("chanyuan_skill")!="fumo-zhangfa")
    return notify_fail("�㲻����ϰ������ܣ�\n");
   if((int)me->query("PKS",1)>=5)
    return notify_fail("��е��������أ������ټ�����ϰ����ħ�ȷ����ˣ�\n");
   if(!objectp(weapon))
		return notify_fail("�������ȣ������ϰ����ħ�ȷ�����\n");
	if((string)weapon->query("skill_type")!="staff")
		return notify_fail("��ʹ�õ��������ԣ�\n");
 return 1;  


}


mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

mapping *query_all_action(object me)
{
return action;	
}

string query_type()    
{                      
	return "staff";
}
string query_base()  
{
	return "staff";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

string *query_perform()
{
	return ({"fumo","xiangyao"});
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/fumo"))
  return 200;
  return 80;
}
