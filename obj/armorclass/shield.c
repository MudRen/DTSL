
#include <armor.h>

inherit SHIELD;
#include "armorsave.h"

void create()
{
   set_name("��������", ({ "shield"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("armor_prop/armor", 2);
   }
   setup();
}
