#include <weapon.h>

inherit SPEAR;

void create()
{
   set_name("��ǹ", ({ "spear" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");   
     set("material", "iron");
     set("long", "����һ�˳�ǹ���Ƚϳ��ء�\n");
     set("wield_msg","$N���$n�������У�����һ�������˸�ǹ����\n");
     set("unequip_msg", "$N���������е�$n��\n");
   }
   init_spear(25,100,100);
   setup();
}