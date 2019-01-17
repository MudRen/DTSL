// weapon.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_weapon(int damage, int strong,int max_strong)
{
	if( clonep(this_object()) ) return;
    set("strong",strong);
	set("max_strong",max_strong);
	set("flag",0);
	set("weapon_prop/damage", damage);
	//set("flag", (int)flag | EDGED);
	set("skill_type", "sword");
	set("defence",({"��","��"}));
	set("verbs",({"��","��"}));
}

