
#include <weapon.h>

inherit FORK;

void create()
{
   set_name("��ǹ", ({ "fork" }) );
   set_weight(700);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("material", "iron");
     set("long", "����һ����ǹ��\n");
     set("wield_msg", "$N�ó�$n,����һ�������˸�ǹ����\n");
     set("unequip_msg", "$N����$nվ�á�\n");
   }
   init_fork(35,130,130);
   setup();
}
