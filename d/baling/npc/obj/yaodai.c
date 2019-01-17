
#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
   set_name(HIG"Ñü´ø"NOR, ({ "yaodai"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "¸±");
     set("value",1000);
     set("armor_prop/armor",8);
     //set("armor_prop/dodge",-1);
   }
   setup();
}
