
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
   set_name(HIY"��"NOR, ({ "hammer" }) );
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("material", "iron");
     set("long", "����һ���𴸣�������������ء�\n");
     set("wield_msg", "$N�ó�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n�ŵ����ϡ�\n");
   }
   init_hammer(75,280,280);
   setup();
}
