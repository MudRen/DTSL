#include "weaponsave.h"

varargs void init_whip(int damage, int strong,int max_strong)
{
   if( clonep(this_object()) ) return;

   set("weapon_prop/damage", damage);
   set("flag", 0 );
   set("strong",strong);
   set("max_strong",max_strong);
   set("skill_type", "whip");
   set("org_name","");
	set("user","");
	set("user_skill",1);
	set("temp_skill",1);
   set("defence",({"��","��"}));
		set("verbs",({"��"}));
}

