
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("¹��", ({ "lujiao" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",300);
		set("material", "iron");
		set("wield_msg", "$N����$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�Ż������䡣\n");
	}
	init_blade(30,30,30);
	setup();
}
