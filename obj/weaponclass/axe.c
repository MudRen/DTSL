

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("����", ({ "axe" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 400);
		set("material", "steel");
	}
	init_axe(25,80,80);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�������\n");

// The setup() is required.

	setup();
}
