
#include <armor.h>

inherit NECK;
#include "armorsave.h"

void create()
{
   set_name("��������", ({ "neck"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("armor_prop/armor", 2);
   }
   setup();
}
