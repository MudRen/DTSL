
#include <armor.h>

inherit ARMOR;

#include "armorsave.h"

void create()
{
   set_name("��������", ({ "armor"}) );
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
