
#include <armor.h>

inherit NECK;

void create()
{
   set_name("»¤¾±", ({ "neck"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "¸ö");
     set("armor_prop/armor", 2);
   }
   setup();
}
