
#include <weapon.h>

inherit AXE;

void create()
{
   set_name("����", ({ "axe" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("leitai_weapon",1);
     set("material", "iron");
     set("long", "����һ�����ӡ�\n");
     set("wield_msg", "$N�ó�$n,�������Ρ�\n");
     set("unequip_msg", "$N����$nվ�á�\n");
   }
   init_axe(40,300,300);
   setup();
}
