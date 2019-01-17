
#include <armor.h>

inherit ARMOR;

void create()
{
   set_name("¿ø¼×", ({ "armor"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "¼þ");
     set("armor_prop/armor", 2);
   }
   setup();
}
