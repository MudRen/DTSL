// ��ħ��
//�ռ��书��

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N���������Ҹ��ɳ�һ����ɫ˿����ͬʱ�����������������������������\n"+
                  "��������������������������洩��֯��һ���ñ��޷������������Ļ�Բ����ֱ\n"+
                  "��$n��$l��",
        "apply_factor": 2,
        "name" : "������Ӱ",
        "damage_type": "����"
]),

([      "action": "$N��һ����Ȼ��ɵĽ�����̬�������������$w����ʲ�����������һ�����߰㣬\n"+
                  "�����ػ����۵�·�ߣ�����$n��",
        "apply_factor": 5,
        "name" : "��ħ����",
        "damage_type": "����"
]),

([      "action": "$N����$w�����ֳ������Ƶ����ƣ�Ȼ����ʮ���������Ȧ��������΢��Ӱ����\n"+
                  "�����ȥ������$n��",
        "apply_factor": 10,
        "name" : "ǧ�����",
        "damage_type": "����"
]),

([      "action": "$Nֻ�Գ����һ��Ĵָ���أ�����Ʈ�裬��������û�������Ƶġ����ޱ���ӯ����ܽ\n"+
              "����̬��$w�������а�����ָ��ɱ����$n������$n����˷�������Ӱ��磬��һ����\n"+
              "������������",
        "apply_factor": 7,
        "name" : "��ħ����",
        "damage_type": "����"
]),

([  "action": "$N��$w���߰�����们������ȡ$n�ᾱ���պø���$n��������һ�̻�������ʱ������\n"+
              "֮���ʹ�Է�������֮�У�$n��Ҫ���������Ͷ�ء� ",
        "apply_factor": 8,
        "name" : "��ħ����",
        "damage_type": "����"
]),
});

string *parry_weapon=({

"$N��ע������$w֮�ϣ�ֻ������һ����ס��$n��$v��\n",
"$Nһ����Ц��$w���һ��ԲȦ����$n��$v��ȥ��\n",
"$N���е�$w������һ�㣬���õ�ס$n��$v��\n",
"$N����Խ��$w�糤���۾�һ�㣬���õ�ס$n��$v��\n"

});

string *parry_hand=({

"$N���е�$w��ͬ����һ�㣬����$n������$n��æ�˿�������һ���亹��\n",
"$N���е�$wһ�ᣬ��������һ�㵲ס��$n�Ĺ�����\n",
"$Nһ�����е�$w��һ��������ס��$n�Ĺ��ơ�\n",
"$N���е�$w��ͬ����һ�㣬����$n��$l��$n��æ�˿�������һ���亹��\n"

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
        object weapon;
        
       
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("�����������ѧϰ��ħ����\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("���õ��������ԡ�\n");
        
     return 1;  
        
       
}

int practice_skill(object me)
{
      
object weapon;
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("�������������ϰ��ħ����\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("���õ��������ԡ�\n");
      
     return 1; 
}

string *query_perform()
{
        return ({"yulong","moying"});    
}


string query_type()  
{
	return "whip";
}

string query_base()
{
	return "whip";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
	
	return 150;
}