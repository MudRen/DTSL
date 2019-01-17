
#include <armor.h>

inherit WAIST;

void create()
{
   set_name("»¤Ñü", ({ "waist"}) );
   set_weight(1800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "¸±");
     set("armor_prop/armor", 2);
   }
   setup();
}
