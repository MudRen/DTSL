
#include <weapon.h>

inherit BLADE;

void create()
{
   set_name("����", ({ "blade" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
	 set("super",3);
     set("value", 4000);
     set("material", "iron");
     set("long", "����һ���ɶ����ɴ���ĸֵ���\n");
     set("wield_msg", "$N���һ�����λε�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
   }
   init_blade(45,120,120);
   setup();
}
