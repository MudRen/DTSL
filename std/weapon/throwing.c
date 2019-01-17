
#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

varargs void init_throwing(int damage, int strong,int max_strong)
{
   if( clonep(this_object()) ) return;

   set("weapon_prop/damage", damage);
   set("flag", 0);
   set("strong",strong);
   set("max_strong",max_strong);
}

void setup()
{
   // ::setup();
   seteuid(getuid());

   if( clonep(this_object()) ) return;

   set("skill_type", "throwing");
   set("defence",({"��","��"}));
		set("verbs",({"��"}));
}
