
#include <armor.h>

inherit ARMOR;

#include "armorsave.h"

void create()
{
   set_name("¿ø¼×ÀàĞÍ", ({ "armor"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "¼ş");
     set("armor_prop/armor", 2);
   }
   setup();
}
