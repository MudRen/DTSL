
#include <weapon.h>

inherit JIAN;

void create()
{
   set_name("�", ({ "jian" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 2000);
     set("material", "iron");
     set("long", "����һ����ﵡ�\n");
     set("wield_msg", "$N�ó�һ��$n�������С�\n");
     set("unequip_msg", "$N�����е�$n������䡣\n");
   }
   init_jian(45,120,120);
   setup();
}
