//��ӥǹ����
//�м�-->�ռ��书��

inherit SKILL;
#include <ansi.h>
mapping *action=({
 ([ "action":"$N����$w���һζ���һ�С���ҹ���롹��$n��$l��ȥ",
    "apply_factor": 2,
    "name" : "��ҹ����",
    "damage_type":"����",
  ]),
  ([ "action":"$N���һ����$w���·ַɣ�һ�С����¸�������$w��Ϊһ��Բ��ֱȡ$n��$l",
    "apply_factor": 5,
    "name" : "���¸���",
    "damage_type":"����",
  ]),
  ([ "action":"ֻ��$N����һ��������$w�����벻���ĽǶȴ���$n��$l����һ�С�����ºڡ�",
    "apply_factor": 10,
    "name" : "����º�",
    "damage_type":"����",
  ]),
  ([ "action":"$Nʹ��һ�С�����Ϯ�¡���$wһ������������Ĺ켣����$n��$l",
    "apply_factor": 7,
    "name" : "����Ϯ��",
    "damage_type":"����",
  ]),
 ([ "action":"$N����ǰ��ʹ������Ӱ���Ρ�������$w�������ޣ���������$n��$l��ȥ",
    "apply_factor": 4,
    "name" : "��Ӱ����",
    "damage_type":"����",
  ]),
([ "action":"$N�����ڿն���һ�С�ҹ���С���������죬��$n��$l�Ͳ���ȥ",
    "apply_factor": 6,
    "name" : "ҹ����",
    "damage_type":"����",
  ]),
});   

string *parry_weapon=({

"$N����$wһ�죬������һ�Σ���������ǹ������ס��$n��$v��\n",
"$N������ˣ�����$wһ�ᣬ৵�һ�����˸����ߣ�����$n��$v��\n",
"$N����$w����ҵ㣬�����������£���ȴǡ���ô��ط�ס��$n��$v��\n",
"$N�ͺ�һ��������$wһ����Ȼ��һ�������üܿ�$n��$v��\n"

});

string *parry_hand=({

"$N��ȫ����$n�Ľ�����$wֱ����$n�ļ��$nһ������æ���ƺ��ˡ�\n",
"$N����$wһ�ᣬ����һ�����ߣ�$n���ò����к��ˡ�\n",
"$N����һת���㿪��$n�Ľ�����ͬʱ$w����һ�̣�$nһ������æ���˿�����\n",
"$N�������񣬿�׼$n�Ľ���֮�ƣ��͵ش̳�����$n�Ľ�����Ϊ���У�\n"

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
string *query_perform()
{
  return ({"fengyu","fengsha"});
}
string query_type()    
{                      
	return "spear";
}
string query_base()  
{
	return "spear";
}

int valid_learn(object me)
{

        int i = (int)me->query_skill("fuying-spear", 1);
	object weapon;
        if (i>199) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ���ϰ�ˡ� \n");
	if(!objectp(weapon=me->query_temp("weapon"))||
		weapon->query("skill_type")!="spear")
			return notify_fail("������ǹ�����ѧϰ��ӥǹ����\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
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
  if(me->query("perform_quest/fengyu")||
     me->query("perform_quest/fengsha"))
  return 200;
  return 80;
}
