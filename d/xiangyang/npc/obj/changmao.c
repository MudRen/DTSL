
#include <weapon.h>
//#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name("长矛", ({ "chang mao","mao","spear" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long","这是一杆长矛，枪头雪白澄亮。\n");
		set("value",600);
		set("material", "steel");
	}
	init_spear(20,90,90);

	set("wield_msg", "$N「唰」地一声抽出一杆$n握在手中，$n的枪尖扑棱扑棱晃了两下。\n");
	set("unwield_msg", "$N将手中的$n放到地上。\n");

	setup();
}
