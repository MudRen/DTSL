
#include <weapon.h>

inherit HAMMER;

void create()
{
   set_name("����", ({ "hammer" }) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
      set("material", "iron");
     set("long", "����һ���ɶ����ɴ����������\n");
     set("wield_msg", "$N���һ��$n�������У����˼��Ρ�\n");
     set("unequip_msg", "$N�����е�$n�����˼��ϡ�\n");
   }
   init_hammer(70,200,200);
   setup();
}
