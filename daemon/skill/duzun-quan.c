// ����ȭ �����书
//force+parry=150~180--180~220--280~320

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�������˫ȭ�͵ػӳ���һ�С�������졹ֱ����$n��$l!",
        "apply_factor": 5,
        "name" : "�������",
       "damage_type": "����"
]),

([  "action": "$N�������У�һ�С��������������ȭ���͵ػӳ�����һȭ֮���·�������!",
        "apply_factor": 5,
        "name" : "�������",
        "damage_type": "����"
]),

([      "action": "$N˫����ȭ˽�ƣ��仯Ī��Ĺ���$n����һ�С�����׺�����",
        "apply_factor": 5,
        "name" : "����׺�",
        "damage_type": "����"
]),

([  "action": "$N˫ȭʮ�ֽ��棬һ�С�������ɽ�����ֻ������������¶��ϴ���$n��$l!",
        "apply_factor": 5,
        "name" : "������ɽ",
        "damage_type": "����"
]),

([  "action": "$Nһ����Х��һ�С�Ω�Ҷ���,һȭ�����������쿪�죬�����Ƶ�֮��!",
        "apply_factor": 5,
        "name" : "Ω�Ҷ���",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"ֻ��$N����$n��$v������һ��$n��$v��$n���ò����˿�����\n",
"$N��ȫ����$n��$v�������Ը�����ٶȴ���$n��$l������Χκ���԰㻯����$n�Ľ�����\n",
"$N˫ȭʮ�ֽ������ؼ汸����ס��$n�Ľ�����\n",
"$N˫ȭ���һƬȭӰ��������$n�Ľ�����\n"

});

string *parry_hand=({

"$N������ӭ��$n�Ľ�����ֻ������һ����˫�����˺󼸲���\n",
"$Nȭ�����ң���ͬ��ǧ��Ӱ��$n���Ʋ��ã���æ���˿�����\n",
"$N��ʽ�Ͻ�������˿�����ң�ʹ$n�Ľ������ò��޹�������\n",
"$N��ȭ������һ����������$n�Ľ�����\n"

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

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ����ȭ��\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ����ȭ��\n");
     return 1;
}

string query_type() 
{
	return "hand";
}

string query_base()
{
	return "cuff";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}


int skill_damage(object me,object victim)
{
  int factor=0;
  
  if(me->query_skill("duzun-quan",1)>=120)
  factor=40;
  
  if(me->query_skill("duzun-quan",1)>=180)
   factor +=60;
     
  return factor;
}

int skill_parry(object me,object victim)
{
  int factor=0;
  
  if(me->query_skill("duzun-quan",1)>=120)
  factor=40;
  
  if(me->query_skill("duzun-quan",1)>=180)
   factor +=30;
 
  return factor;
}