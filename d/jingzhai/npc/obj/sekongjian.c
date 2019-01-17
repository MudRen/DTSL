
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIC"色空剑"NOR, ({ "sekong jian", "jian","sword" }));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("rumor",1);
		set("no_save",1);
		set("long", "这是一柄宝剑，上面刻着「色空」二字。\n");
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(200,300,300);
	setup();
}
