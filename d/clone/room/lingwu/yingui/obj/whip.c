
#include <weapon.h>

inherit WHIP;

void create()
{
   set_name("Ƥ��", ({ "whip" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("material", "iron");
     set("long", "����һ��Ƥ�ޡ�\n");
     set("wield_msg", "$N���һ��$nž�ض���һ����\n");
     set("unequip_msg", "$N�����е�$n�������䡣\n");
   }
   init_whip(35,120,120);
   setup();
}
