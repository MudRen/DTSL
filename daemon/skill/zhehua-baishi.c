// �ۻ���ʽ��
//�����ɵ�����
//�м�-->�ռ��书��

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$Nһʽ���������󡹺��ط��֣�$w��β�����ϵ��������벻����λ������$n��ȥ��",
        "apply_factor": 2,
        "name" : "��������",
       "damage_type": "����"
]),

([  "action": "$NͻȻһ����Х��һ�С�������Ӱ������ʵʵ�����Ƕ��ǵĻ���$n��$l��",
        "apply_factor": 5,
        "name" : "������Ӱ",
        "damage_type": "����"
]),

([      "action": "����$N��ζ�������Ȼ����$n�Ҳ�������,������Ѱ�ޡ����$w������$n��ȥ��",
        "apply_factor": 10,
        "name" : "����Ѱ��",
        "damage_type": "����"
]),

([  "action": "$N����ͻȻ����������Ʈ��������ͻȻѸ�ݵ�ʹ��һ�С��仨���桹����$n��$l��",
        "apply_factor": 7,
        "name" : "�仨����",
        "damage_type": "����"
]),
([  "action": "$N���е�$w����һ������Ȧ�ӣ����С��췽��԰��һ������ʱ����$n�ۻ����ң���֪���룡",
        "apply_factor": 4,
        "name" : "�췽��԰",
        "damage_type": "����"
]),
([  "action": "$Nһʽ���֦ͻ�֡����س��֣���ָ�ɵ��������벻����λ������$n��ȥ��",
        "apply_factor": 6,
        "name" : "�֦ͻ��",
        "damage_type": "����"
]),
([  "action": "$NͻȻһ����Х��һ�С�ƬƬ�仨������ʵʵ�����Ƕ��ǵĻ���$n��$l��",
        "apply_factor": 3,
        "name" : "ƬƬ�仨",
        "damage_type": "����"
]),
});

string *parry_weapon=({

"$N������һ��ת��������ʫ�黭�⣬����һ��$w��ס��$n��$v��\n",
"$N���΢Ц����ȫ��������ս���У�����$w���������һ�У��Ѿ���$n��$v�񿪣�\n",
"$N�����ؼ���ת������$w���迪��������ƬƬ�ʻ�׹�䣬��$n���ò�����$v��\n",
"$N����$w����˿����ɱ��������֮ʽ����ۻ�֮�ˣ�˿������ص�����$n��$v��\n"

});

string *parry_hand=({

"$N�������ţ��Գ�һ�ɷ������ε����ӣ�����$w�㵽��ֹ�ص�ס��$n�Ľ�����\n",
"����$N�Ķ������������������赸���ֺ����ڹ��Ͱٶ��ʻ���$wһ��һ��֮�䣬$n�Ľ�����Ϊ���У�\n",
"$N��Ȼ������$w�����л����г�һ��ʫ��������ʫ�����֮�У���ס��$n�Ľ�����\n",
"$N�����Գ�һ����Ȼ�⾳���ڲ�����֮�䣬$w�ѷ�ס��$n�Ľ��������ȵ�$n�˺󼸲���\n"

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
	
	//if(me->query("huajian_skill")!="zhehua-baishi")
	// return notify_fail("���޷�ѧϰ�ۻ���ʽ��\n");
	 
	weapon=me->query_temp("weapon");
	if (!weapon||weapon->query("skill_type")!="blade")
            return notify_fail("ֻ��װ������ı����ſ���ѧϰ�ۻ���ʽ��\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
	weapon=me->query_temp("weapon");
	if (!weapon||weapon->query("skill_type")!="blade")
            return notify_fail("ֻ��װ������ı����ſ�����ϰ�ۻ���ʽ��\n");
     return 1;
}

string *query_perform()
{
	return ({"zhi","zhe"});   
}


string query_type() 
{
	return "blade";
}

string query_base()
{
	return "blade";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}



int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/zhi"))
  return 200;
  return 100;
}

