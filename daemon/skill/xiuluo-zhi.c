// ����ָ���Ⱥ���ի��

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N������Ĵָ֮�ϣ�ӭ��$n�Ľ�����һ�С���������ָ������$n��$l!",
        "apply_factor": 2,
        "name" : "��������ָ",
       "damage_type": "����"
]),

([  "action": "$Nʳָ���������������ʵ��һ�С��޴�����ָ������$n��$l!",
        "apply_factor": 5,
        "name" : "�޴�����ָ",
        "damage_type": "����"
]),

([      "action": "$N��ָ�ȶ����ң����д�����һ�С��޾�����ָ�����ꡯ��һ������$n!",
        "apply_factor": 8,
        "name" : "�޾�����ָ",
        "damage_type": "����"
]),

([  "action": "$N����ָ���˸����ߣ�һ������ֱ��$n��$l����ȥ������һ�С���������ָ��!",
        "apply_factor": 4,
        "name" : "��������ָ",
        "damage_type": "����"
]),
([  "action": "$NСĴָ���������Ʈ��������ͻȻһ�С���������ָ������$n��$l!",
        "apply_factor": 6,
        "name" : "��������ָ",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$N��ָ΢΢һ�������ƿ�֮���γ����һ����ֻ��һ������������$n��$v��\n",
"$N��ָ��ס�任���û�����������֮��$n���һ������æ�ջ�$v��\n",
"$N�������ᣬָ��˿�������κ�ɱ����������Լ���ֳ�ʥŮ�Ĺ�ԣ�$n��$v���������Ҳ�޷������ˡ�\n",
"$N�������紦Ů���������ã���ָ������㳯$n�Ķ�ͷ��ȥ��$n��æ����$v�˿���\n"

});

string *parry_hand=({

"$N����΢������ָ˲��任�̡��������ȼ���������$n�Ĺ��Ʋ��ɵû���������\n",
"$N��ָ��ס������ңң��ָ��$n��Ҫ��֮������Ȼһ��δ������$nȴ�Ҳ���$N��������\n",
"$N����һЦ����������һ�㣬$n��ʱ��������ս��ֻ�С�$N��ָһ�ӣ��Ѿ���ס�����е�������\n",
"$N��ָ�ڵ���һ����ֻ��һ�����������滮��һ��Բ�����������ʯ��$n��ȥ���ȵ�$n�˺�һ����\n"

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
       
     if((int)me->query("PKS",1)>=5)
	return notify_fail("��ɱ����̫���ˣ��޷�ѧϰ����ָ��\n");
     if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
     return notify_fail("�����ֲ���ѧϰ����ָ��\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if((int)me->query("PKS",1)>=5)
	return notify_fail("��ɱ����̫���ˣ��޷���ϰ����ָ��\n");
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ����ָ!\n");
     return 1;
}

string *query_perform()
{
	return ({"lingxi"});   
}


string query_type() 
{
	return "hand";
}

string query_base()
{
	return "finger";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  
  return 120;
}
