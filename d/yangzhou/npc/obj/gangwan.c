
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(BLU"¸ÖÍó"NOR, ({ "gang wan","wan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Éú¸Ö");
     set("unit", "¸±");
     set("value",1500);
     set("armor_prop/armor",12);
     set("armor_prop/dodge",1);
   }
   setup();
}
