//Ӱ�ӽ���.
//�м�-->�ռ��书��

inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����ͻȻ����һ�С���Ӱ�ɽ����Կ����ޱȵ��ٶȴ���$n��$l����",
    "apply_factor": 2,
    "name" : "��Ӱ�ɽ�", 
    "damage_type":"����",
  ]),
 ([ "action":"$N���������������ĥ������һ�С���Ӱ���١�ͻȻһ������$n��$l��",
    "apply_factor": 5,
    "name" : "��Ӱ����", 
    "damage_type":"����",
  ]),
  ([ "action":"$N��������$w��Ȼ�͵ش���$n��$l������һ�С������Ӱ����",
    "apply_factor": 10,
    "name" : "�����Ӱ",
    "damage_type":"����",
  ]),
  ([ "action":"$N��$w��Ȼ������ǧ��Ӱ��������˷�����$n��$l������һ�С�ǧ��Ѱ������",
    "apply_factor": 7,
    "name" : "ǧ��Ѱ��",
    "damage_type":"����",
  ])});   

string *parry_weapon=({

"$N��$w�ϳ�����ɱ������ȫ���˼��Լ������壬ƴ��һ�е���$n��$v��\n",
"$N���е�$w���綾��һ�㣬�ӹ���ĽǶȴ������ȵ�$n�ջ�$v��\n",
"$N���յ�һЦ��$w���Ź������·������$n��$v��\n",
"$N��ȫ�������������$w֮�ϣ��͵�һ�̣����ý�$n��$v������\n"

});

string *parry_hand=({

"$N����ʽ�����ޱȣ��������һ�㣬һ��������������ס��$n�Ľ�����\n",
"$N�������綾�ߣ���ʽ������ȣ���$n�����嶯��֮�ʣ�$N��Ȼ��$w��ס��$n�Ľ�����\n",
"$NͻȻɳ�Ƶ�һ�У��������Ǻ�������$w�û��ݳ�����ס��$n�Ľ�����\n",
"$N��ȫ����$n�Ľ���������$wһ�ۣ�����$n�Ķ�ͷ��$nһ������æ�����˻�����\n"

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

int practice_skill(object me)  
{
   object weapon;
   
   if(me->query_skill("yingzi-jianfa",1)<200)
    return notify_fail("ֻ��Ӱ�ӽ����ﵽ���ټ���ſ�����ϰ��ߣ�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
 
 return 1;  
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
	
	if(me->query("job_office_number/ɱ������")<10)
	 return notify_fail("���ɱ�����񹦼�̫���ˣ�������ѧϰӰ�ӽ�����\n");
	
	if(me->query_skill("yingzi-jianfa",1)>=me->query("job_office_number/ɱ������")*5)
	 return notify_fail("�����������ɱ�����񹦼������ܼ���ѧϰӰ�ӽ�����\n");
	
	if(!objectp(weapon=me->query_temp("weapon")))
     return notify_fail("�����޽������ѧϰӰ�ӽ�����\n");
	 if(weapon->query("skill_type")!="sword")
	return notify_fail("�����޽������ѧϰӰ�ӽ�����\n");
	return 1;
}
mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}


string *query_perform()
{
	return ({"ci","xunming"}); 
}


int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/ci"))
  return 210;
  return 80;
}
