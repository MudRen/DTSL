// ˮ���䷨���������书��
//�м�-->�ռ��书��

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�������һζ�������$w��ע��������һ�С���ɽ��ˮ������$n��$l����",
        "apply_factor": 2,
        "name" : "��ɽ��ˮ",
        "damage_type": "����"
]),

([  "action": "$N����תʽ��$w��������$n������һ�С����˫Ӱ������$n��$l��!",
        "apply_factor": 5,
        "name" : "���˫Ӱ",
        "damage_type": "����"
]),

([      "action": "$N���ֵ�ס��$n�Ĺ�����$w����һ�С����Ʒ��桹ɨ��$n��$l����",
        "apply_factor": 10,
        "name" : "���Ʒ���",
        "damage_type": "����"
]),

([  "action": "$N������ǰ�͵�һ�ݣ�$wһ�ᣬ��ס��$n�Ľ��������$w����������һ�С���ˮ�޾������˹�ȥ��",
        "apply_factor": 7,
        "name" : "��ˮ�޾�",
        "damage_type": "����"
]),

([  "action": "$N����$w��Ϊ��ʽ������$n��ǰ������һ�Σ�����һ��$w��һ�С�������ơ�����$n!",
        "apply_factor": 8,
        "name" : "�������",
        "damage_type": "����"
]),
});

string *parry_weapon=({

"$N���е�$w��������һ�㣬��ס$n��$v�����������ĵ�����$n�Ľ�����\n",
"$N΢΢һЦ�����е�$w��$n�������ȥ��$nһ������æ�ջ���$v��\n",
"$N���е�$w����һ��Բ��������������գ���ס��$n��$v��\n",
"$N��$wֱ��$n�����̹�ȥ��$n����֮�£�ֻ���ջ���$v��\n"

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


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
        
}

mapping *query_all_action(object me)
{
return action;	
}

int valid_learn(object me)
{
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("�����������ѧϰˮ���䷨��\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("���õ��������ԡ�\n");
	
     return 1;  
        
       
}

int practice_skill(object me)
{
      
object weapon;
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("�������������ϰˮ���䷨��\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("���õ��������ԡ�\n");
      
     return 1; 
}

string *query_perform()
{
	return ({"yanyu","youyun"});    
}


string query_type()  
{
	return "whip";
}

string query_base()
{
	return "whip";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/yanyu"))
  return 190;
  return 90;
}

int skill_parry(object me,object victim)
{
  if(me->query("perform_quest/yanyu"))
  return 200;
  return 100;
}