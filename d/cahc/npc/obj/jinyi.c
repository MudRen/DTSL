#include <armor.h>
inherit CLOTH;

void create()
{
   set_name("½õÒÂ", ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("unit", "¼þ");
     set("value", 80);
     set("armor_prop/armor", 5);
   }
   setup();
}
