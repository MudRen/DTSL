
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIG"ն�˵�"NOR, ({ "zhan lang dao","dao","blade" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
	 set("super",6);
     set("value", 4000);
     set("material", "iron");
	 set("no_save",1);
     set("long", "����һ�������ɵı������������[ն��]���֡�\n");
     set("wield_msg", "$N���һ�����λε�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
   }
   init_blade(65,150,150);
   setup();
}
