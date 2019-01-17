
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(HIY"ÓðÃ«"NOR, ({ "yu mao","mao"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "ÓðÃ«");
     set("unit", "¸ö");
     set("armor_prop/armor",1);
   }
   setup();
}
