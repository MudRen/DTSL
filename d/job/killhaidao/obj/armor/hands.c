
#include <armor.h>

inherit HANDS;

void create()
{
   set_name("����", ({ "hands"}) );
   set_weight(900);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "˫");
     set("armor_prop/armor", 2);
   }
   setup();
}
