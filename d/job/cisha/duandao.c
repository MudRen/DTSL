
#include <weapon.h>
//#include <ansi.h>
inherit BLADE;

void create()
{
	set_name("短刀", ({ "duan dao","dao","blade" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是把短刀，锋利无比。\n");
		set("value",100);
		set("material", "steel");
	}
	init_blade(20,60,60);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插回腰间的刀鞘。\n");

	setup();
}
