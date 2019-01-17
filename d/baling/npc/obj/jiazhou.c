
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(HIB"¼×ëÐ"NOR, ({ "armor"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "¼þ");
     set("value",2000);
     set("armor_prop/armor",15);
     set("armor_prop/dodge",-2);
   }
   setup();
}
