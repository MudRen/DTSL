// ���޺��ļ���
//���ܵȼ���Ϊ �� �� �� �����֡�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N���ڻ���ǣ���������������ˣ��͵�һȭ��$n��$l����ȥ��",
        "apply_factor": 5,
        "name" : "����",
       "damage_type": "����"
]),

([  "action": "$N���ڸ�֨��֨�������죬ͻ��$N�쳤���磬��$n�������´�����",
        "apply_factor": 5,
        "name" : "����",
        "damage_type": "����"
]),

([      "action": "$N����ͻȻ���㣬ֻ����֨һ����˫��������һ�㳯$n������",
        "apply_factor": 5,
        "name" : "����",
        "damage_type": "����"
]),

([  "action": "$NͻȻ���緢��һ����˫ȭƴ����$n��ȥ������˫��Ҳ�ǲ�ͣ�Ľ�����",
        "apply_factor": 5,
        "name" : "����",
        "damage_type": "����"
]),

});

mapping query_action(object me,object victim)
{
   return action[random(sizeof(action))];
}


string *query_perform()
{
	return ({"suimu"});   
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
  if(me->query("target_lev")=="low")
  return 10;
  else
  if(me->query("target_lev")=="mid")
  return 50;
  else
  return 120;
  
}
