
#include <armor.h>

inherit BOOTS;
#include "armorsave.h"

void create()
{
   set_name("ѥ������", ({ "boots"}) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "˫");
     set("armor_prop/armor", 2);
   }
   setup();
}
