
#include <armor.h>

inherit WRISTS;

void create()
{
   set_name("����", ({ "wrists"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "˫");
     set("armor_prop/armor", 2);
   }
   setup();
}
