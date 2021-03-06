// sweeper.c by Whitestone

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_sweeper(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "sweeper");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "sweeper" }) );
	}
}

