// ǧ��ͭ��
//�ռ��书��

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N��$w����һ����һ����Ȧ�ӣ�ÿ����Ȧ��ͭ��������������֮���ۡ�\n"+
                  "������һ˲��˲���ƿ�$n������������£�����һ�С�ͭ�����䡹�� ",
        "apply_factor": 2,
        "name" : "ͭ������",
        "damage_type": "����"
]),

([  "action": "$N��̤�沽�����β��ϱ仯��ͬʱ���з���Х����һ��ħ�ð��������Ȼ������\n"+
              "�����ھ��е�$n�����������Ҳ��ʼ¶��������",
        "apply_factor": 5,
        "name" : "��������",
        "damage_type": "����"
]),

([      "action": "$N�����̤���������ǵ�ƾ������$w����$n��ͷ��������ζ���\n"+
                  "�Ƕȶ�ʱ����Ź����������Ǳ仯��ǧ��ħ���ؼ�����Ȼ������˼��",
        "apply_factor": 10,
        "name" : "ǧ����ͷ",
        "damage_type": "����"
]),

([  "action": "$N�Ѻ�����ǰ��$w�����Ƴ���������$w������Ծ�����������£�����һ����\n"+
              "�����µ����ƣ�$n�������񶼱�$w���������е�$wԽ��Խ���Ʋ��ɵ���",
        "apply_factor": 7,
        "name" : "��ָ����",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$N��ע������$w֮�ϣ���������ԲȦ���ԹŹֵ�������ס��$n��$v��\n",
"$N����$w��Ͽ��е�ħ���������򵥵���ʽ��$n��$v��ȥ��\n",
"$N���е�$w������һ�㣬���õ�ס$n��$v��\n",
"$N����Խ��$w�糤���۾�һ�㣬���õ�ס$n��$v��\n"

});

string *parry_hand=({

"$N���е�$w��ͬ����һ�㣬����$n������$n��æ�˿�������һ���亹��\n",
"$N���е�$wһ�ᣬ��������һ�㵲ס��$n�Ĺ�����\n",
"$Nһ�����е�$w��һ��������ס��$n�Ĺ��ơ�\n",
"$N���е�$w��ͬ����һ�㣬�ӷ�����˼�ĽǶȷ�ס��$n�Ľ�����\n"

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
         return notify_fail("�����������ѧϰǧ��ͭ����\n");
        if(weapon->query("skill_type")!="sword")
         return notify_fail("���õ��������ԡ�\n");
        
     return 1;  
        
       
}

int practice_skill(object me)
{
      
object weapon;
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("�������������ϰǧ��ͭ����\n");
        if(weapon->query("skill_type")!="sword")
         return notify_fail("���õ��������ԡ�\n");
      
     return 1; 
}

string *query_perform()
{
	return ({"wanhuan"});    
}


string query_type()  
{
	return "sword";
}

string query_base()
{
	return "sword";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
int skill_damage(object me,object victim)
{
  
  return 200;
}