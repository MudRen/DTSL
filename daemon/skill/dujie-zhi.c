// �ɽ�ָ��������Ժ��
//�м�-->�ռ��书

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�������һ��������ʳָʹ��һ�С��������ġ�����$n��$l��",
        "apply_factor": 2,
        "name" : "��������",
       "damage_type": "����"
]),

([  "action": "$N�����͵�Խ��˫��ʳָ��$n��$l����������һ�С�����콵����",
        "apply_factor": 5,
        "name" : "����콵",
        "damage_type": "����"
]),

([      "action": "$N˫��ʳָ��Ȼ������������$n��ĥ����������$n��ȫ��ҪѨ������һ�С��ն���������",
        "apply_factor": 10,
        "name" : "�ն�����",
        "damage_type": "����"
]),

([  "action": "$N����ʳָ��$n������һ�Σ�����ʳָ�͵ش����������һ�С�����ɽ١�����$n��$l��",
        "apply_factor": 7,
        "name" : "����ɽ�",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$N���΢Ц����ָ����֮�Σ���ʱʹ$n��$v���޴�����֮�У�\n",
"$N��ָ΢΢һ�����������ص�ж����$n�Ľ�����\n",
"$N˫ָ���������$nֻ�����Լ��Ľ�������ˣ���Щ�����ڵء�\n",
"$N����ָ��$n�������ȥ��$n��æ���ˣ����е�$v��Щ�������ڵأ�\n"

});

string *parry_hand=({

"$Nָ���任�޳������ش����ؼܿ���$n�Ľ�����\n",
"$N΢΢һЦ����ָһ����$n�Ľ����Ѿ��������߽⣡\n",
"$N��ָһ�������������Ѱ���Ž����Ļ��ᡣ\n",
"$Nָ����ס�任�����Ǽ򵥵���ʽ��ȴ��ס��$n��ȫ������֮����\n"

});

mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}
mapping *query_all_action(object me)
{
return action;	
}

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

int valid_learn(object me)
{
    if(me->query("chanyuan_skill")!="dujie-zhi")
    return notify_fail("�㲻��ѧϰ������ܣ�\n");
    if((int)me->query("PKS",1)>=5)
    return notify_fail("��ֻ�����Լ��������أ������ڼ���ѧϰ��ȥ�ˣ�\n");
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ�ɽ�ָ��\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(me->query("chanyuan_skill")!="dujie-zhi")
    return notify_fail("�㲻����ϰ������ܣ�\n");
      if((int)me->query("PKS",1)>=5)
    return notify_fail("��ֻ�����Լ��������أ������ڼ�����ϰ��ȥ�ˣ�\n");
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ�ɽ�ָ��\n");
     return 1;
}

string *query_perform()
{
	return ({"liudao","yizhi"});   
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
  if(me->query("perform_quest/liudao"))
  return 200;
  return 80;
}
