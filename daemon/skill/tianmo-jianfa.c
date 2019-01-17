//��ħ����
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����ƫ�棬��������Ȱ�������һ�С���Ӱ����������$n��",
    "apply_factor": 2,
    "name" : "��Ӱ����",
    "damage_type":"����",
  ]),
 ([ "action":"$N����ͻȻ���������仯������Խ��һ�С���ħ���衹����$n��$l��",
    "apply_factor": 3,
    "name" : "��ħ����",
    "damage_type":"����",
  ]),
  ([ "action":"$N������ˣ�����һ��Բ��������һ�С���ӰԲ�衹���ش�������$n������֮����",
    "apply_factor": 4,
    "name" : "��ӰԲ��",
    "damage_type":"����",
  ]),
  ([ "action":"$N���к������ң�������ĥ������һ�С���ħ��Ӱ������$n��",
    "apply_factor": 5,
    "name" : "��ħ��Ӱ",
    "damage_type":"����",
  ])});   


string *parry_weapon=({

"$N������ˣ�����һ��Բ��������$w��$n��$v����һ�𣬷�������һ����\n",
"$N���ο��ٵػ��˼��Σ�����$w�����벻���ĽǶȻ��˹�ȥ�����ü�ס$n��$v��\n",
"$Nһ�����е�$w��ƴ����ס��$n��$v��ֻ������һ�������Ľ���\n",
"$Nˢ��һ����������������$w���Ữ��$v���������䣬����Զ����\n"

});

string *parry_hand=({

"$N���Ϲ����Ц��һ������������$w����Ҫ����$n��$l��$n�Ĺ��Ʋ��ɵ�ͣס�ˡ�\n",
"$N�˺󼸲�������$wңָ$n��$l����ס��$n�Ľ���֮�ơ�\n",
"$N����$wһ�ӣ����������Ѱ���Ž����Ļ��ᡣ\n",
"$N����$wһ�ᣬ���Ǽ򵥵���ʽ��ȴ��ס��$n��ȫ������֮����\n"

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
	
		
	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")       
        return notify_fail("�����޽������ѧϰ��ħ������\n");
	
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

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
int skill_damage(object me,object victim)
{
  
  return 20;
}