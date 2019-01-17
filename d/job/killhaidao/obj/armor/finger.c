
#include <armor.h>

inherit FINGER;

void create()
{
   set_name("»¤Ö¸", ({ "finger"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "Ã¶");
     set("armor_prop/armor", 2);
   }
   setup();
}
