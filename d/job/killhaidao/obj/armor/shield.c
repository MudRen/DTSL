
#include <armor.h>

inherit SHIELD;

void create()
{
   set_name("»¤¶Ü", ({ "shield"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "¸ö");
     set("armor_prop/armor", 2);
   }
   setup();
}
