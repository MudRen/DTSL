
#include <armor.h>

inherit WRISTS;
#include "armorsave.h"

void create()
{
   set_name("»¤ÍóÀàĞÍ", ({ "wrists"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "Ë«");
     set("armor_prop/armor", 2);
   }
   setup();
}
