
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("ͭ��", ({ "tong xiao","tong","xiao" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 400);
		set("material", "iron");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	init_sword(30,80,80);
	setup();
}
