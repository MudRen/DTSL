

#include <weapon.h>

inherit SPEAR;

void create()
{
	set_name("ǹ", ({ "spear" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "steel");
	}
	init_spear(10,80,80);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�������\n");

// The setup() is required.

	setup();
}
