
#include <weapon.h>

inherit DAGGER;

void create()
{
   set_name("ذ��", ({ "dagger" }) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("material", "iron");
     set("long", "����һ��Сذ�ס�\n");
     set("wield_msg", "$N�ó�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n������䡣\n");
   }
   init_dagger(15,30,30);
   setup();
}
