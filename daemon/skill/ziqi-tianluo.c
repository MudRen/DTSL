// ��������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N���ָ߾٣������չ�ᣬʮָ���ţ���������س�$n��$l��ץȥ!",
        "apply_factor": 2,
        "name" : "����",
       "damage_type": "����"
]),

([  "action": "$N�˳�����Զ������ӹ��������$n��˫�����Ծ����ַ�Ӳ��һ�У�",
        "apply_factor": 2,
        "name" : "����",
        "damage_type": "����"
]),

([      "action": "$N��ŭ��Ц�����ƴ������������������Ӱ������ǰ̤�Ĳ���������ǵص���$n��ȥ��",
        "apply_factor": 2,
        "name" : "����",
        "damage_type": "����"
]),

([  "action": "$N�Ų��沽������������Ʈ�Ʋ����ļ������������$n��࣬���ּ���$n��$l��",
        "apply_factor": 2,
        "name" : "����",
        "damage_type": "����"
]),

});


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
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
