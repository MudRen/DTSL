// axe.c

inherit SKILL;

mapping *action=({
([ "action":"$N����ͷ��$n��ȥ��",
    "dodge":20,
    "damage":10,
    "force":10,
    "damage_type":"����",
]),
([  "action":"$N����һ�Σ�����ͷ��$nͷ���͵Ŀ�ȥ!",
    "dodge":10,
    "damage":15,
	"damage_type":"����",
]),
([
 "action":"$N������ǰ��ͦ����$n���˹�ȥ",
 "dodge":10,
 "damage":10,
 "damage_type":"����",
])



});   







mapping query_action(object me,object weapon)
{
	return action[random(sizeof(action))];
}

string query_type()
{
	return "base";
}


string perform_action_file(string action)
{
	return __DIR__"axe/"+action;
}

int valid_learn(object me)  
{

        int i = (int)me->query_skill("axe", 1);
        if (i>400) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ� \n");
        return 1;
}
