

#include <weapon.h>

inherit BLADE;

void create()
{
   set_name("����ĵ�", ({ "blade" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("material", "iron");
     set("no_in_corpse",1);
     set("nogive_player",1);
     set("lianrou_blade",1);
     set("long", "����һ�����������������С�֣����ᡣ\n");
     set("wield_msg", "$N���һ�����λε�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
   }
   init_blade(25,80,80);
   setup();
}
