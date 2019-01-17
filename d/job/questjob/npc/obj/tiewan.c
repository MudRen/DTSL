
#include <armor.h>

inherit WRISTS;

void create()
{
   set_name("Ìú»¤Íó", ({ "hu wan","wan"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "¸±");
     set("value",100);
     set("armor_prop/armor",2);
   }
   setup();
}
