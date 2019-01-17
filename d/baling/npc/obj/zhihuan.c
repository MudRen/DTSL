
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(HIC"Ö¸»·"NOR, ({ "zhihuan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "Ã¶");
     set("value",600);
     set("armor_prop/armor",6);
     set("armor_prop/dodge",2);
   }
   setup();
}
