
#include <armor.h>

inherit HEAD;

void create()
{
   set_name("ͷ��", ({ "head"}) );
   set_weight(3500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("armor_prop/armor", 2);
   }
   setup();
}
