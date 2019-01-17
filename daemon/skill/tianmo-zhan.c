//��ħն��type : dagger.
//�ռ��书��
//
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N����΢΢���Σ����е�$w�д���һ����׵ĺ�Х֮��һ�С�����ն����$n��$l��նȥ��",
    "apply_factor": 2,
    "name" : "����ն",
    "damage_type":"����",
  ]),
 ([ "action":"$N����һЦ�������������壬���е�$wͻȻ����$n��$l,����һ�С�����ն��!",
    "apply_factor": 5,
    "name" : "����ն",
    "damage_type":"����",
  ]),
  ([ "action":"$N˫����ס$w����������һ֧������һ�С�����ն����$n��$l����ȥ��",
    "apply_factor": 10,
    "name" : "����ն",
    "damage_type":"����",
  ]),
  ([ "action":"$N���ڵ������ڲ��ϱ仯���������ƣ�ͻȻһ�С�����ն��ն��$n��$l!",
    "apply_factor": 7,
    "name" : "����ն",
    "damage_type":"����",
  ]),
    
 });   

string *parry_weapon=({

"$N����΢΢���Σ�˫����ס$w��������$n��$v��\n",
"$N���ڵ������ڲ��ϱ仯���������ƣ�ֻ������һ��������$n��$v��\n",
"$N����һЦ�������������壬����$wһ����������$n�Ľ�����\n",
"$N��̾һ����������$w֮�ϣ�����$n��$v��\n"

});

string *parry_hand=({

"$N���Ϲ����Ц��һ������������$w����Ҫ����$n��$l��$n�Ĺ��Ʋ��ɵ�ͣס�ˡ�\n",
"$N�˺󼸲�������$wҥָ$n��$l����ס��$n�Ľ���֮�ơ�\n",
"$N����$wһ�ӣ����������Ѱ���Ž����Ļ��ᡣ\n",
"$N����$wһ�ᣬ���Ǽ򵥵���ʽ��ȴ��ס��$n��ȫ������֮����\n"

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
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("��ʹ�õ��������ԡ�\n"); 
    return 1;  

}

int practice_skill(object me)
{
  object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("��ʹ�õ��������ԡ�\n");
 
 return 1;  


}


mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];

}
mapping *query_all_action(object me)
{
return action;	
}

string *query_perform()
{
	return ({"lingxiao","duanhun"});
}
string query_type()
{
	return "dagger";
}
string query_base()
{
	return "dagger";
}
mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

void hit_ob(object me,object victim)
{
   if(!me->query_temp("actionp_hit/lingxiao"))
   return;
   
   "/daemon/skill/effskill/lingxiao.c"->hit_ob(me,victim);
   return;
}

int skill_damage(object me,object victim)
{
	
	return 180;
	
}