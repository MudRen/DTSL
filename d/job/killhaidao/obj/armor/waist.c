
#include <armor.h>

inherit WAIST;

void create()
{
   set_name("����", ({ "waist"}) );
   set_weight(1800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("armor_prop/armor", 2);
   }
   setup();
}
