//���α޷���
//�м�-->�ռ��书��

inherit SKILL;
#include <ansi.h>
mapping *action=({
 ([ "action":"$NͻȻһ�ݣ���ճ�$nб�˹�����������ӥ�Ӹߴ������½���ȡ��ԭ���Ӱ�����ʳ��\n"+
             "˫����ע���飬��ǻ��ݳ�һ˿���Ž�����Ц�⡣",
    "apply_factor": 2,
    "name" : "��ӥ���",
    "damage_type":"����",
  ]),
  ([ "action":"$N��Ȼ$w����������ľ����ȵ���ǰ��$n��Ҷ��Ʈ�����ٶ���ʱ��ǶȾ���и�ɻ���\n"+
              "�ȵ�$nֻ��Ӳƴһ����",
    "apply_factor": 5,
    "name" : "�����Ҷ",
    "damage_type":"����",
  ]),
  ([ "action":"$N��$w������մ���$n������һ�У���ʱ����ȫ�������Ƴ��˰������������л�ʽ��\n"+
              "�����˿���",
    "apply_factor": 10,
    "name" : "������¥",
    "damage_type":"����",
  ]),
  ([ "action":"$N��м�����һ���������Ƶ�$w���д���΢��һ�£�������ʱ���ɰ�ǧ���Ӱ��ˮ��к\n"+
              "�ص���$n��ȥ��",
    "apply_factor": 7,
    "name" : "��������",
    "damage_type":"����",
  ]),
 ([ "action":"$N��Цһ��������΢�$w����һ����ʱ���ɵ��â�⣬��ˮ������$n������ȴ����һ\n"+
             "�ţ�����$n�����̣�����ʱ���ݲ��ȣ�����̾Ϊ��ֹ��",
    "apply_factor": 4,
    "name" : "��Į����",
    "damage_type":"����",
  ]),
([ "action":"$N����һ��Ц��$w���գ�������ʽ�����������е�$n�޲��е����а���������ɱ�ţ�\n"+
            "���ò��������ܡ�",
    "apply_factor": 6,
    "name" : "͵��Ϯ��",
    "damage_type":"����",
  ]),
});   

string *parry_weapon=({

"$N����$wһ�죬������һ�Σ����������Ӱ����ס��$n��$v��\n",
"$N΢΢һЦ�����е�$w�����߰㳯$n��$v��ȥ��$nһ������æ���˿�����\n",
"$N���е�$w������һ�㣬������ӿ�س�$n�����̾�ȥ��$n��æ�ջ�$v���˿�����\n",
"$N�ͺ�һ��������$wһ�Σ�ֻ��ž��һ��������$n��$v��\n"

});

string *parry_hand=({

"$N����$wһ�죬������һ�Σ����������Ӱ����ס��$n�Ľ�����\n",
"$N΢΢һЦ�����е�$w�����߰㳯$n�����̾�ȥ��$nһ������æ���˿�����\n",
"$N���е�$w������һ�㣬������ӿ�س�$n�����̾�ȥ��$n��æ���к��˿�����\n",
"$N�ͺ�һ��������$wһ�Σ�ֻ��ž��һ��������$n�����ƣ�\n"

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
  return ({"kun"});
}
string query_type()    
{                      
	return "whip";
}
string query_base()  
{
	return "whip";
}

int valid_learn(object me)
{
	object weapon;
	if(!objectp(weapon=me->query_temp("weapon"))||
		(string)weapon->query("skill_type")!="whip")
			return notify_fail("�����ޱޣ����ѧϰ���α޷���\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
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
  if(me->query("perform_quest/kun"))
  return 200;
  return 80;
}
