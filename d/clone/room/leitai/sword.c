
#include <weapon.h>

inherit SWORD;

void create()
{
   set_name("�ֽ�", ({ "sword","jian" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("leitai_weapon",1);
     set("material", "iron");
     set("long", "����һѰ���ĸֽ���������Լ�����߽��ء�\n");
     set("wield_msg", "$N���һ�����λε�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
   }
   init_sword(25,300,300);
   setup();
}
