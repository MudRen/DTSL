//�쵶�˾����μұ��书��
//�м�-->�ռ��书��

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N��Ѷ�ײ����ڶ�֮ʽ���͵ػӳ�һ��������һ�С���绷�塹����$n��$l����",
    "apply_factor": 2,
    "name" : "��绷��",
    "damage_type":"����",
  ]),
 ([ "action":"$N����$wһ�������о�Ȼ�ε���$n�����һ�С���͡ˮ�ơ�����$n��$l!",
    "apply_factor": 5,
    "name" : "��͡ˮ��",
    "damage_type":"����",
  ]),
  ([ "action":"$N����$w�γ�һƬ��Ӱ��ͻȻ���лӳ�һ����һ�С�ʯ����Ȫ���͵ؿ���$n��$l����",
    "apply_factor": 10,
    "name" : "ʯ����Ȫ",
    "damage_type":"����",
  ]),
  ([ "action":"$N��������$n��ס��ת����ͻȻ����һ��������һ�С���Ҷ����硹����$n��$l��",
    "apply_factor": 7,
    "name" : "��Ҷ�����",
    "damage_type":"����",
  ]),
  ([ "action":"$Nһ��$w,����$n�Ľ���������һ�С��쵶���项����$n��$l����",
     "apply_factor": 4,
     "name" : "�쵶����",
     "damage_type":"����",
    ]),
  ([ "action":"$N�����͵�����$w���������˵���������һ�С��쵶ӭ�͡�����$n��$l��",
     "apply_factor": 6,
     "name" : "�쵶ӭ��",
     "damage_type":"����",
    ]),  
   ([ "action":"$N�����³��������Ƚ����Ӷ�$w���Ͽ�ȥ��һ�С��쵶Ѱ�꡹����$n��$l��",
     "apply_factor": 3,
     "name" : "�쵶Ѱ��",
     "damage_type":"����",
    ]), 
   ([ "action":"$N����$w�ķ��������������һ��ֱ����$n��$l,����һ�С��쵶���ġ���",
     "apply_factor": 8,
     "name" : "�쵶����",
     "damage_type":"����",
    ]), 
 });   

string *parry_weapon=({

"$N���������е�$w������һ�ɰ�����һ�и���$n��$v��\n",
"$N����$w���һ��������������һ����һ��ʮ���ε��⽫$n��$v�������棡\n",
"$N˿��Ҳ�����ã����е�$w���������������ȵ�$n���������е�$v��\n",
"$N����$wһ�ӣ�ǿ������ʽ��$n���һ����$v�Ľ�������̼䱻�����һ�ɶ�����\n"

});

string *parry_hand=({

"$N���һ�������е�$w��$n��������ȥ��$n���һ������æ�����˽�����������\n",
"$N���˷��أ����е�$w��ֱ��$n��ͷ����ȥ��$n��$N����ƴ�������������Լ��Ľ����Ѿ�ȫ��������\n",
"$Nһ�����е�$w��$nֻ����һ�����������������æ���ؽ�����������\n",
"$Nһ����Ц�����е�$w��Ȼ��һ�з�ס��$n�Ľ�������������֮�ʣ�\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

int valid_learn(object me)
{
        object weapon;
        
	if(me->query_skill("badao",1)>0)
        	return notify_fail("��ѧϰ�˰Ե����޷���ѧϰ�쵶�˾���\n");

	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("�����޵������ѧϰ�쵶�˾���\n");
     return 1;  

}

int practice_skill(object me)
{
  object weapon;
	
	if(me->query_skill("badao",1)>0)
        	return notify_fail("��ѧϰ�˰Ե����޷���ѧϰ�쵶�˾���\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        
 return 1;  


}


mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];

}

mapping *query_all_action(object me)
{
return action;	
}

string *query_perform()
{
	return ({"bajue","daoyi"});
}
string query_type()
{
	return "blade";
}
string query_base()
{
	return "blade";
}
mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/bajue"))
  return 210;
  return 100;
}
