//������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����ð��������������һ�����߳�$n��$l����ȥ!",
        "apply_factor": 10,
        "name" : "������",
        "damage_type": "����"
]),

([  "action": "$N���еĺ����������������͵س�$n��$l����ȥ!",
        "apply_factor": 10,
        "name" : "������",
        "damage_type": "����"
]),

([      "action": "$N����һ����˫�����ص���ֻ��һ��������������$n��$l�������ȥ��",
        "apply_factor": 10,
        "name" : "������",
        "damage_type": "����"
]),

([  "action": "$N˫��ƽ�ƣ�$nֻ����һ�ɷ�������֮�����Լ�ѹ��!",
        "apply_factor": 10,
        "name" : "������",      
        "damage_type": "����"
]),

});


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}


string query_type()  
{
	return "hand";
}

string query_base()
{
	return "strike";
}
int skill_damage(object me,object victim)
{
  return 100;
}
