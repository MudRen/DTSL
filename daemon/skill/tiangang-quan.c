// ���ȭ��������Ժ.
//�м�-->�ռ��书

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�������ȣ�˫ȭ�������磬һ�С����Űݿ͡�����$n��$l��",
        "apply_factor": 2,
        "name" : "���Űݿ�",
       "damage_type": "����"
]),

([  "action": "$N����վ�ȣ�˫ȭ���˸�Բ������$n���д�ȥ������һ�С�ͯ�Ӱݷ𡹴���$n��$l��",
        "apply_factor": 5,
        "name" : "ͯ�Ӱݷ�",
        "damage_type": "����"
]),

([      "action": "$N��ȭ���������£���ס��$n�Ľ�����ͬʱ��ȭ�͵ػ��˸����߻���������һ�С����ǰ�β����",
        "apply_factor": 10,
        "name" : "���ǰ�β",
        "damage_type": "����"
]),

([  "action": "$N�����п�����ת���㿪��$n�Ĺ�����ͬʱ��ȭ����$n����·����ȭ������·������һ�С�˫����������",
        "apply_factor": 7,
        "name" : "˫������",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$N���΢Ц��˫ȭ�������أ���ʱʹ$n��$v���޴�����֮�У�\n",
"$N��ȭ΢΢һ�����������ص�ж����$n�Ľ�����\n",
"$Nһ��˫ȭ��$nֻ�����Լ��Ľ�������ˣ���Щ�����ڵء�\n",
"$N��˫ȭ��$n�������ȥ��$n��æ���ˣ����е�$v��Щ�������ڵأ�\n"

});

string *parry_hand=({

"$N˫ȭ�任�޳������ش����ؼܿ���$n�Ľ�����\n",
"$N΢΢һЦ��˫ȭһ�ӣ�$n�Ľ����Ѿ��������߽⣡\n",
"$N˫ȭһ�ӣ����������Ѱ���Ž����Ļ��ᡣ\n",
"$N˫ȭ��ס�任�����Ǽ򵥵���ʽ��ȴ��ס��$n��ȫ������֮����\n"

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
    if(me->query("chanyuan_skill")!="tiangang-quan")
    return notify_fail("�㲻��ѧϰ������ܣ�\n");
    if((int)me->query("PKS",1)>=5)
    return notify_fail("��ֻ�����Լ��������أ������ڼ���ѧϰ��ȥ��!\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ���ȭ��\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(me->query("chanyuan_skill")!="tiangang-quan")
    return notify_fail("�㲻����ϰ������ܣ�\n");
      if((int)me->query("PKS",1)>=5)
    return notify_fail("��ֻ�����Լ��������أ������ڼ�����ϰ��ȥ��!\n");
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ���ȭ��\n");
     return 1;
}

string *query_perform()
{
	return ({"tiangang","zhenhun"});   
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
  if(me->query("perform_quest/tiangang"))
  return 180;
  return 90;
}
