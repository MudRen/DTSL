//whip.c
inherit SKILL;



string query_type()
{
	return "base";
}


string perform_action_file(string action)
{
	return "/daemon/skill/whip/"+action;
}