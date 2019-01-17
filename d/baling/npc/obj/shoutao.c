
#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
   set_name(HIC"ÊÖÌ×"NOR, ({ "shoutao"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "Ã¶");
     set("value",300);
     set("armor_prop/armor",2);
     //set("armor_prop/dodge",2);
   }
   setup();
}
