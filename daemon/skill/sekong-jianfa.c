//ɫ�ս�
//�м�-->�ռ��书

inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����$wһ����һ�С������ῴ�����١�������$w����һ������������$n��$l��",
    "apply_factor": 1,
    "name" : "�����ῴ������", 
    "damage_type":"����",
  ]),
 ([ "action":"$N��ƮƮ������Ծ��ͻȻһ�С�¥���¼���˫�ܡ�ʹ��������$wһת������$n$l��",
    "apply_factor": 2,
    "name" : "¥���¼���˫��",
    "damage_type":"����",
  ]),
  ([ "action":"$N����ת����ͣ��һ�С��ݽ�Ǽ�Ѿ�������������$w��紵�������ŵ�$n�ۻ����ң�",
    "apply_factor": 3,
    "name" : "�ݽ�Ǽ�Ѿ�����",
    "damage_type":"����",
  ]),
  ([ "action":"$N��$w��ǰ������ͻȻ����$w��$n��ɨ��ȥ����һ�С�δ�����Ƿ�ˡ���",
    "apply_factor": 4,
    "name" : "δ�����Ƿ��",
    "damage_type":"����",
  ]),
  ([ "action":"$N����ǰ����Ȼ������Ծ������$wһʽ�����ݲ�ռ����������׼$n����һ����",
    "apply_factor": 5,
    "name" : "���ݲ�ռ������",
    "damage_type":"����",
  ]),
  ([ "action":"$N����һЦ��һʽ���滨����Ů���㡹��$w����һ��������$n��",
    "apply_factor": 6,
    "name" : "�滨����Ů����",
    "damage_type":"����",
  ]), 
  ([ "action":"$N��̬���У�����$w���أ�һ�С����Ҳ�����������Ӳ���˼��ĽǶȻ���$n��$l��",
    "apply_factor": 7,
    "name" : "���Ҳ��������",
    "damage_type":"����",
  ]), 
  ([ "action":"$N����һ����ʹ�˸�������������������������$w���һ��������׼$n$l��ȥ��",
    "apply_factor": 8,
    "name" : "��������������",
    "damage_type":"����",
  ]), 
  ([ "action":"$N����$wֱָ$n$l��һ�С��߽���������ӡ�����ػ���$n��$l��",
    "apply_factor": 9,
    "name" : "�߽����������",
    "damage_type":"����",
  ]), 
  ([ "action":"$N��̬���У�����$wƾ��һָ��һ�С����Ѻ��ѧС��������һ������$n��$l��",
    "apply_factor": 10,
    "name" : "���Ѻ��ѧС��",
    "damage_type":"����",
  ]), 
  ([ "action":"$Nʹһ�С�ֻΪ�����С�١�������$w����������$n��$l����������",
    "apply_factor": 10,
    "name" : "ֻΪ�����С��",
    "damage_type":"����",
  ]), 
  ([ "action":"$N����$w����$w��ͣ�ز����ţ��������ϵķ��������С�ȴ���ް�����̨��ʹ������࣡",
    "apply_factor": 10,
    "name" : "ȴ���ް�����̨",
    "damage_type":"����",
  ]), 
});   


string *parry_weapon=({

"$N���Ϻ��ޱ��飬��ϲ����ŭ�������ǲ������һ�����е�$w��ȴ���õ�ס$n��$v��\n",
"$N��Хһ����������ת����ͬ�����µ��ʻ�����ѩ�еĲ��ɣ�৵�һ��$w�Ѿ���ס��$v��\n",
"$N����$w���²��㣬�����ʻ�ʢ���������������̣��������ɵļ�����ʽ����ס��$n��$v��\n",
"$N�����������һ�ˣ�����$wһ�����ܿ���$n��$v��ֻ������������㡣\n"

});

string *parry_hand=({

"$N����һת��$w��������һ���������������Ÿ���������Ȼ��ס��$n�Ľ�����\n",
"���$n�Ľ�����$N�ƺ��������⣬����$wһ����һ��Ư����Բ����Ȼ��$n�赲ס��\n",
"$N������ӯ���ѣ���������һ�㣬����������˿�������������е�$w�������ʺ磬��ȫ��ס��$n�Ľ�����\n",
"$N����$w��׼$n���������͵�һ�д�ȥ��������ʽ�������ϣ�����$n������ͣס��\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}



mapping query_action(object me,object weapon)
{
    return action[random(sizeof(action))];
}
mapping *query_all_action(object me)
{
return action;	
}


string query_type()    
{                      
	return "sword";
}
string query_base()  
{
	return "sword";
}

int valid_learn(object me)
{
	object weapon;
	
	if((int)me->query("PKS",1)>=5)
	return notify_fail("��ɱ����̫���ˣ��޷�ѧϰɫ�ս�����\n");
	
	if(!objectp(weapon=me->query_temp("weapon"))||
	   weapon->query("skill_type")!="sword")
			return notify_fail("�����޽������ѧϰɫ�ս���\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;
   
   if((int)me->query("PKS",1)>=5)
   return notify_fail("��ɱ����̫���ˣ��޷���ϰɫ�ս�����\n");
	
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
 
 return 1;  


}
string *query_perform()
{
	return ({"kong","se"}); 
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
  
  if(me->query("perform_quest/kong"))
  factor=100;
  
  if(me->query("execute_quest/xinyoulingxi")){
   factor +=150;
   
  }
  if(me->query("execute_quest/jianxintongming")){
   factor +=200;
   
  }
 
  return factor;
}
