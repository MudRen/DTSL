#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIY"��ɳ��"NOR, ({ "sword","jian" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
set("no_save",1);
		set("super",3);
		set("material", "iron");
		set("wield_msg", "$N���$n,���˸��������������С�\n");
		set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword(125,180,180);
	setup();
}
