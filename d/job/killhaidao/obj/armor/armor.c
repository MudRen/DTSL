
#include <armor.h>

inherit ARMOR;

void create()
{
   set_name("����", ({ "armor"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("armor_prop/armor", 2);
   }
   setup();
}
