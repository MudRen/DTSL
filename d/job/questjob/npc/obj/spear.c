#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
set_name("��ǹ", ({ "spear" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
      set("material", "iron");
     set("long", "����һ����ǹ��\n");
     set("wield_msg", "$N���$n�������У�����һ�������˸�ǹ����\n"NOR);
     set("unequip_msg", "$N���������е�$n��\n");
   }
   init_spear(80,180,180);
   setup();
}

