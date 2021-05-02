
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(YEL"½ðË¿¼×"NOR, ({ "jia"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("unit", "¼þ");
     set("value", 400);
     set("rumor",1);
     set("armor_prop/armor",150);
   }
   setup();
}
