//�������ԡ�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N���������������Ĳ����������뾲�ĸ�ɮ����ʩ������������ӡ����һ��������������ɢ������\n",
        "apply_factor": 2,
        "name" : "��������ӡ",
       "damage_type": "����"
]),
([      "action": "$N���������ӡ�����Ϻ�����֣�ֻ��һ�����˳�$nӿȥ��",
        "apply_factor": 6,
        "name" : "������ӡ",
       "damage_type": "����"
]),
([  "action": "$Nһ�����壬��Цһ����ٿ��������ȥ����������$n��ͬʱ���ְ���ʨ��ӡ������һ�����͡���",
        "apply_factor": 10,
        "name" : "��ʨ��ӡ",
        "damage_type": "����"
]),
([  "action": "$N���ְ�����ʨ��ӡ������һ�ӣ�ֻ��һ����ǽ��$n����ȥ��",
        "apply_factor": 7,
        "name" : "��ʨ��ӡ",
        "damage_type": "����"
]),

([  "action": "$N���ڸ�ӡ��Ϊ�⸿ӡ��Ĵָ������࣬�������£�$n��ʱӦӡ�����ٺᷭ��ȥ��",
        "apply_factor": 6,
        "name" : "�⸿ӡ",
        "damage_type": "����"
]),

([      "action": "$N�ڸ�ӡ��������������ս���������Դ������������ֵ��ھ�ӭͷʹ����",
        "apply_factor": 4,
        "name" : "�ڸ�ӡ",
        "damage_type": "����"
]),

([  "action": "$N������ȭӡ��ͻȻȭ��ͻ�䣬�����������ǣ���$n��$l����ȥ��",
        "apply_factor": 3,
        "name" : "��ȭӡ",
        "damage_type": "����"
]),
([  "action": "$N��������ӡ�����ƽ���֮�䣬�����������˷����������ھ���$nӿȥ��",
        "apply_factor": 8,
        "name" : "����ӡ",
        "damage_type": "����"
]),
([  "action": "$N����ƿӡ����ƿ��ȭ���ٷǸ߶ȼ��е�һ�ţ�������һ��ǽ��ֱ��$nѹ��ȥ��",
        "apply_factor": 9,
        "name" : "��ƿӡ",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$N���΢Ц�������������أ���ʱʹ$n��$v���޴�����֮�У�\n",
"$N����΢΢һ�����������ص�ж����$n�Ľ�����\n",
"$Nһ�����ƣ�$nֻ�����Լ��Ľ�������ˣ���Щ�����ڵء�\n",
"$N�����Ƴ�$n��������ȥ��$n��æ���ˣ����е�$v��Щ�������ڵأ�\n"

});

string *parry_hand=({

"$N���Ʊ任�޳������ش����ؼܿ���$n�Ľ�����\n",
"$N΢΢һЦ������һ�ӣ�$n�Ľ����Ѿ��������߽⣡\n",
"$N����һ�ӣ����������Ѱ���Ž����Ļ��ᡣ\n",
"$N���Ʋ�ס�任�����Ǽ򵥵���ʽ��ȴ��ס��$n��ȫ������֮����\n"

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
    if(me->query_temp("weapon"))
    return notify_fail("�����������������ѧϰ�������ԣ�");
    return 1;  
}

int practice_skill(object me)
{
     if(me->query_temp("weapon"))
    return notify_fail("�������������������ϰ�������ԣ�");
    return 1;
}



string query_type() 
{
	return "hand";
}

string query_base()
{
	return "strike";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

string *query_perform()
{
  return ({"budong","jingang","shizi","fu","zhiquan"});
}


int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/jzzy"))
  return 150;
  if(me->query_skill("jiuzi-zhenyan",1)>180)
  return 220;
  return 120;
}
