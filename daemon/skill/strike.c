// strike.

inherit SKILL;

mapping *action=({
([ "action":"$N����վס,������ǰһ��,һ��[��������]����$n��",
    "dodge":20,
    "damage":10,
    "force":10,
    "damage_type":"���",
]),
([  "action":"$N�������һ��,˫���Ƴ�,����һ��[��ɽ����]��$n�͵���ȥ!",
    "dodge":10,
    "damage":15,
	"damage_type":"���",
]),
([
 "action":"$NͻȻת��,һ��[��ͷ����]��$n���˹�ȥ",
 "dodge":10,
 "damage":10,
 "damage_type":"���",
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
	return __DIR__"hand/"+action;
}