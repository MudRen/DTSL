
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("���", ({ "yang jiao","jiao" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
		set("wield_msg", "$N����$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�Ż������䡣\n");
	}
	init_sword(30,30,30);
	setup();
}
