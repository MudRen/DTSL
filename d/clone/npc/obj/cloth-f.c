
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("Ů�Ӿ�װ", ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("unit", "��");
     set("long","����һ���������������·�\n");
     set("value", 40);
     set("armor_prop/armor", 2);
   }
   setup();
}
