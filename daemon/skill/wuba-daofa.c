//��Ե���������������
//�м�-->�߼�

inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N���γ��ȣ�����$wһת��ʩչ�������ĵ�����һ�С��������¡���$n��$l����ȥ��",
    "apply_factor": 2,
    "name" : "��������", 
    "damage_type":"����",
  ]),
 ([ "action":"$N����һת������һ��Բ����ͻȻ��������ʩչ�������̵�����������һ�С�����֮������",
    "apply_factor": 5,
    "name" : "����֮��",
    "damage_type":"����",
  ]),
  ([ "action":"$N����ͻȻ������ר����·����Ȼ��������·����ֻ��һ�С�����ն����$n��$l��ȥ��",
    "apply_factor": 10,
    "name" : "����ն",
    "damage_type":"����",
  ]),
  ([ "action":"����ν��һ��̣�һ���ա���$NͻȻʩչ���̵���·�����۵�$n��ǰ��һ�С��ʶ���ԭ����$n��ȥ��",
    "apply_factor": 7,
    "name" : "�ʶ���ԭ",
    "damage_type":"����",
  ]),
  ([ "action":"$N����$w���һ���׹⣬����һ�����ƣ����м����ż��й��Ƴ�$n��ȥ������һ�С����ｭɽ����",
    "apply_factor": 8,
    "name" : "���ｭɽ",
    "damage_type":"����",
  ]),
  
});   


string *parry_weapon=({

"$N����һЦ��һ�����е�$w��Ӳ�Ǹ�$n��$v��\n",
"$N�������Բ��һ�㣬��$n��$v�������棡\n",
"$N��$w�͵س�ǰһ������Ȼ���˼��Լ��İ�Σ��$nһ������æ����$v��\n",
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

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("�����޵������ѧϰ��Ե�����\n");
     return 1;  

}

int practice_skill(object me)
{
  object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        
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


string query_type()    
{                      
	return "blade";
}
string query_base()  
{
	return "blade";
}

string *query_perform()
{
	return ({"sanfen","juehun"});
}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}



int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/sanfen"))
  return 150;
  return 80;
}

