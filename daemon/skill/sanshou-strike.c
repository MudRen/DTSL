// ɢ�ְ��ˡ�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�ľ����總��֮��������$n�����Ų��Ծ��ʼ�ղ����������в��$n��$l����$n�޿��κΣ�",
        "apply_factor": 2,
        "name" : "����֮��",
       "damage_type": "����"
]),

([  "action": "$N�ľ�����һ�Ѽ�����Ӳ����$n���ϣ�ֻҪ$n�����Բ��֤��Ϯ��$n��Ѫ���أ���������",
        "apply_factor": 5,
        "name" : "¨��֮��",
        "damage_type": "����"
]),

([      "action": "$N����¶�����ص���ɫ�������Ȼ�������κα�ī�����ݵ�΢������仯����������\n"+
                  "����ٿ�ؾ�Ө������ִ�����̽�������������ָ���£��ɨ��$n��$l��",
        "apply_factor": 10,
        "name" : "꼻�һ��",
        "damage_type": "����"
]),

([  "action": "ֻ��$N�򵥵�һ�������ܰ��������ŵ�����ת�����ģ�ƫ������$n�����޴ӣ����ݽ��Ӿ���\n"+
              "�������˽�����Ӳ������ͻȻŤ����������һ����������ʩ��",
        "apply_factor": 7,
        "name" : "��������",
        "damage_type": "����"
]),

([  "action": "������$n��ǰ���󣬾�������$N�����β�������������Ʈ������Ȼ�ֻ�Ϊ�޳���Ө�����֣�\n"+
              "������������ݲ�������",
        "apply_factor": 4,
        "name" : "�ɻ�ǧ��",
        "damage_type": "����"
]),

([  "action": "$Nٿ���۽������ƺ���$n��$l��������ƽʵ���棬���޻��ɵ���ʽ����ȴ�б仯��\n"+
              "���������޷�׽�����Իøо���",
        "apply_factor": 6,
        "name" : "�任����",
        "damage_type": "����"
]),

([  "action": "$Nһ�ָ���һ��̽ǰ����ָ���ƴ����Ѷ������ƣ�վ������ɽ����ʹ��������\n"+
              "�Զ�ҡ��ֺ��ĸо���",
        "apply_factor": 3,
        "name" : "��֮ɽ",
        "damage_type": "����"
]),

([  "action": "$N�������⣬��������Ĳ���ɨ���ӡ�����û��˿�����ɣ�ȴ�ص�$n��Խ�׳ذ벽��",
        "apply_factor": 8,
        "name" : "�ٳ߷���",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$N�������⣬��������Ĳ���ɨ���ӡ�����û��˿�����ɣ��Ѿ�����$n��$v��\n",
"$N�������գ�����ǰ�ƶ��Ƕ����ȵ�$n�ջ�$v���˿�����\n",
"$N��̬���ݵ����������״�����ˣ�ֻ�����һ����һ�ɾ�����������$n��$v��\n",
"$N����¶�����ص���ɫ�����������ָ���£��ɨ��$n��$v����\n"

});

string *parry_hand=({

"$N�������⣬��������Ĳ���ɨ���ӡ�����û��˿�����ɣ��Ѿ�����$n�Ľ�����\n",
"$N�������գ�����ǰ�ƶ��Ƕ����ȵ�$n�ջ���ʽ���˿�����\n",
"$N��̬���ݵ����������״�����ˣ�ֻ�����һ����һ�ɾ�����������$n���ֱۣ�\n",
"$N����¶�����ص���ɫ�����������ָ���£��ɨ��$n�����󴦣�\n"

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
     return 1;  
        
       
}

int practice_skill(object me)
{
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
  return ({"bapu"});
}



int skill_damage(object me,object victim)
{
	int str,inte;
	int damage;
	int add;
	
	str = me->query("str");
	inte = me->query("int");
	
  	if(me->query("perform_quest/bapu")){
  		if(str>=38&&inte>=38){  		
  			damage = 250;
  			add = str-38;
  			if(inte-38>add)
  				add = inte-38;
  			damage = damage+damage*(add/2)*20/100;
  			
  		}
  		else
  		if(str>=35&&inte>=35)
  			damage = 150;
  		else
  			damage = 100;
  	}
  	else
  		damage = 80;
  		
  	return damage;
}
