

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIR"������"NOR, ({ "bawang dao","blade","dao" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("rumor",1);
set("no_sell",1);
     set("super",6);
     set("value", 500);
     set("material", "iron");
     set("long", "������ɽ�ĳ���������\n");
     set("wield_msg", YEL"$N���$n,"+YEL+"���˸��������������С�\n"NOR);
     set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
   }
   init_blade(225,280,280);
   setup();
}
