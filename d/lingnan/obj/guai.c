
#include <weapon.h>

inherit STAFF;

void create()
{
   set_name("�ֹ�", ({ "guai" }) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("material", "iron");
     set("long", "����һ���ֹգ��������ƺ����ᡣ\n");
     set("wield_msg", "$N�ó�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n����������\n");
   }
   init_staff(65,280,280);
   setup();
}
