
#include <weapon.h>

inherit HAMMER;

void create()
{
   set_name("����", ({ "hammer" }) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("leitai_weapon",1);
     set("value", 500);
     set("material", "iron");
     set("long", "����һ�����������������������ᡣ\n");
     set("wield_msg", "$N�ó�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n�����˵��ϡ�\n");
   }
   init_hammer(40,300,300);
   setup();
}
