#include "weaponsave.h"

varargs void init_jian(int damage, int strong,int max_strong)
{
	if( clonep(this_object()) ) return;
    set("strong",strong);
	set("max_strong",max_strong);
	set("flag",0);
	set("org_name","");
	set("user","");
	set("user_skill",1);
	set("temp_skill",1);
	set("weapon_prop/damage", damage);
	//set("flag", (int)flag | EDGED);
	set("skill_type", "jian");
	set("defence",({"��","��"}));
	set("verbs",({"��"}));
}

