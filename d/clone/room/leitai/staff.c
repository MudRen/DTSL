
#include <weapon.h>

inherit STAFF;

void create()
{
   set_name("����", ({ "staff" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("leitai_weapon",1);
     set("material", "iron");
     set("long", "����һ�����ȡ�\n");
     set("wield_msg", "$N�ó�$n,�������е��˵ࡣ\n");
     set("unequip_msg", "$N����$nվ�á�\n");
   }
   init_staff(35,300,300);
   setup();
}
