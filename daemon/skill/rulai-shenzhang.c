// �������ơ�������Ժ��
//�м�-->�ռ��书

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�溬΢Ц��������˿����ɱ�⣬�����������أ�����ǧ��֮����\n"+
                  "������$n��$l����ȥ��$n�پ�ѹ�����أ�",
        "apply_factor": 2,
    		"name" : "�������",
       "damage_type": "����"
]),

([      "action": "$N�����Ʋ��ϱ任���û���������״��������Σ�$n�Ծ�֮�࣬��\n"+
                  "���������У�ֻ��������һ��˼��֮�У�����ѹ�����أ�",
        "apply_factor": 5,
    		"name" : "���ޱ�",
        "damage_type": "����"
]),

([      "action": "$N�����ջأ����ƿ��ƻ������Ƴ���ֻ����������һ����һ��ǿ��\n"+
                  "��������$nײȥ��",
        "apply_factor": 10,
    		"name" : "�����ħ",
        "damage_type": "����"
]),

([      "action": "$NͻȻ����Ծ��$n�Ծ�֮�ֻ࣬��$Nһ������˫�Ʋ��ϱ任��\n"+
                  "ֻ���������ƴ��������$n������",
        "apply_factor": 7,
    		"name" : "����콵",
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
    
    if(me->query("chanyuan_skill")!="rulai-shenzhang")
    return notify_fail("�㲻��ѧϰ������ܣ�\n");
    
    if((int)me->query("PKS",1)>=5)
    return notify_fail("��ֻ�����Լ��������أ������ڼ���ѧϰ��ȥ�ˣ�\n");
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ�������ơ�\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(me->query("chanyuan_skill")!="rulai-shenzhang")
      return notify_fail("�㲻����ϰ������ܣ�\n");
      
      if((int)me->query("PKS",1)>=5)
    return notify_fail("��ֻ�����Լ��������أ������ڼ�����ϰ��ȥ�ˣ�\n");
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ�������ơ�\n");
     return 1;
}

string *query_perform()
{
	return ({"pudu","pomo"});   
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


int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/pudu"))
  return 180;
  return 80;
}

void hit_ob(object me,object victim)
{
   if(!me->query_temp("actionp_hit/pomo"))
   return;
   
   "/daemon/skill/effskill/pomo.c"->hit_ob(me,victim);
   return;
}