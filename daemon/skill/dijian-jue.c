//�μҽ���.
//�м�-->�ռ��书��
inherit SKILL;
#include <ansi.h>

mapping *action=({
  ([ "action":"$N�����ȣ���¶һ˿������һ�С�����ӭ�͡�����$n��$l��",
    "apply_factor": 2,
    "name" : "����ӭ��", 
    "damage_type":"����",
  ]),
 ([ "action":"$N����$wһ�ᣬ������$w֮�ϣ�һ�С�����ط硹ͻȻ����$n��$l��",
    "apply_factor": 10,
    "name" : "����ط�",
    "damage_type":"����",
  ]),
  ([ "action":"$N����Ʈ���������Ĵ����ߣ��͵�һ�С�����է�֡�����$n��$l��",
    "apply_factor": 5,
    "name" : "����է��",
    "damage_type":"����",
  ]),
  ([ "action":"$N����$w����һ��������ֻ����ˢ����һ����$w�ѳ�$n��$l����ȥ������һ�С�������������",
    "apply_factor": 7,
    "name" : "��������",
    "damage_type":"����",
  ])});   

string *parry_weapon=({

"$N��ע������$w֮�ϣ�����ͨ��ƽ����������ס��$n��$v��\n",
"$N����$w���д󿪴��أ������򵥵���ʽ��$n��$v��ȥ��\n",
"$N��Хһ�������е�$w����һ��Բ�������õ�ס$n��$v��\n",
"$N���е�$w����һ������������ǧ���������֮�ɼܿ�$n��$v��\n"

});

string *parry_hand=({

"$N΢΢һЦ�����е�$wˢ��һ������$n������$n��æ�˿�������һ���亹��\n",
"$N���е�$wһ�ᣬ��������һ�㵲ס��$n�Ĺ�����\n",
"$Nһ�����е�$w��һ��������ס��$n�Ĺ��ơ�\n",
"$N���е�$w��ͬ����һ�㣬�ӷ�����˼�ĽǶȷ�ס��$n�Ľ�����\n"

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

string *query_perform()
{
	return ({"ditian","feilong"});    
}

int valid_learn(object me)
{
        object weapon;
        if(!objectp(weapon=me->query_temp("weapon")))
           return notify_fail("�����������ѧϰ�μҽ�����\n");
        if(weapon->query("skill_type")!="sword")
           return notify_fail("���ý����ѧϰ�μҽ�����\n");
	return 1;
}
int practice_skill(object me)  
{
  object weapon;
        if(!objectp(weapon=me->query_temp("weapon")))
           return notify_fail("�������������ϰ�μҽ�����\n");
        if(weapon->query("skill_type")!="sword")
           return notify_fail("���ý������ϰ�μҽ�����\n");
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/dilie"))
  return 120;
  return 100;
}

void hit_ob(object me,object victim)
{
   if(!me->query_temp("actionp_hit/feilong"))
   return;
   
   "/daemon/skill/effskill/feilong.c"->hit_ob(me,victim);
   return;
}
