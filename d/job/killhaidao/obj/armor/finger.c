
#include <armor.h>

inherit FINGER;

void create()
{
   set_name("��ָ", ({ "finger"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "ö");
     set("armor_prop/armor", 2);
   }
   setup();
}
