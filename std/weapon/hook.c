#include "weaponsave.h"

varargs void init_hook(int damage, int strong,int max_strong)
{
   if( clonep(this_object()) ) return;

   set("weapon_prop/damage", damage);
   set("flag", 0);
   set("skill_type", "hook");
   set("strong",strong);
   set("org_name","");
	set("user","");
	set("user_skill",1);
	set("temp_skill",1);
   set("max_strong",max_strong);
   set("defence",({"��","��"}));
   set("verbs",({"��"}));
}
