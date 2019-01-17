// �̺��޷� �η��������£������º�ۡ�ŷ��ٻ
//damage+parry=120~160--160~200-->260~300
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N���лζ�������$w����һ�ڣ�һ�С��沨����������$n��$l����",
        "apply_factor": 4,
        "name" : "�沨����",
        "damage_type": "����"
]),

([  "action": "$N����תʽ��$w��������������һ������Բ����һ�С��˾���ơ�����$n!",
        "apply_factor": 4,
        "name" : "�˾����",
        "damage_type": "����"
]),

([      "action": "$N����$w�����ֳ������Ƶ�����,һ�С��������졹�޼����$n��$l����",
        "apply_factor": 4,
        "name" : "��������",
        "damage_type": "����"
]),

([  "action": "$N��$w��Ȼ������һ�С�������ˮ��,$w��һ��������$n���˹�ȥ��",
        "apply_factor": 4,
        "name" : "������ˮ",
        "damage_type": "����"
]),

([  "action": "$N����$w����$n�����Ƽ򵥵�һ�ޣ�ȴ��$n��֮����,��һ�С���Ԩ���ڡ�����$n!",
        "apply_factor": 4,
        "name" : "��Ԩ����",
        "damage_type": "����"
]),
});

string *parry_weapon=({

"$N���е�$w��������һ�㣬����$n��$v�����������ĵ�����$n�Ľ�����\n",
"$N���е�$w��$n�������ȥ��$nһ������æ���лء�\n",
"$N���е�$w����һ��Բ��������������գ�����$n��$v��\n",
"$N��$wֱ��$n�����̹�ȥ��$n����֮�£�ֻ���ջ���$v��\n"

});

string *parry_hand=({

"$N��$w���糤���۾�����$n�������ȥ��$n����֮��ֻ�ú��˼�����\n",
"$Nһ�����е�$w��$w������֮�仯��һ�����ڣ�����������֮�䣬$n�Ľ���֮��Ҳ��Ϊ���У�\n",
"$N��Цһ�������е�$w�������������������赸�����������$n�Ľ�����\n",
"$N��$w����һ����һ�ģ�һ����������$n�Ľ�����\n"

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
         return notify_fail("�����������ѧϰ�̺��ޣ�\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("���õ��������ԡ�\n");
	
     return 1;  
        
       
}

int practice_skill(object me)
{
      
object weapon;
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("�������������ϰ�̺��ޣ�\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("���õ��������ԡ�\n");
      
     return 1; 
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
  int factor=0;
  
  if(me->query_skill("bihai-bianfa",1)>=120)
  factor=40;
  
  if(me->query_skill("bihai-bianfa",1)>=180)
   factor +=40;
     
  return factor;
}

int skill_parry(object me,object victim)
{
  int factor=0;
  
  if(me->query_skill("bihai-bianfa",1)>=120)
  factor=40;
  
  if(me->query_skill("bihai-bianfa",1)>=180)
   factor +=30;
 
  return factor;
}