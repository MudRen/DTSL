#include "weaponsave.h"

varargs void init_stick(int damage, int strong,int max_strong)
{
   if( clonep(this_object()) ) return;

   set("weapon_prop/damage", damage);
   set("strong",strong);
   set("max_strong",max_strong);
   set("flag",0);
   set("skill_type", "stick");
   set("org_name","");
	set("user","");
	set("user_skill",1);
	set("temp_skill",1);
   set("verbs",({"��"}));
   set("defence",({"��","��"}));
}

