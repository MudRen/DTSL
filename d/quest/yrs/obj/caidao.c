#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("�˵�", ({ "cai dao","dao"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",10);
		set("material", "iron");
		set("wield_msg", "$N���$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(10,20,20);
	setup();
}
