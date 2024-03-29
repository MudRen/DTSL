// sanmending.c 丧门钉
// cck 17/6/97

#include <weapon.h>
// inherit COMBINED_ITEM;
inherit THROWING;
#include "/inherit/item/embed.h"

void create()
{
	set_name("丧门钉", ({ "sangmen ding", "ding" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一枚丧门钉，似乎喂的是“青陀罗花”的毒汁。\n");
		set("value", 1);
		set("no_sell", 1);
		set("material", "steel");
		set("wield_msg", "$N抓出一把丧门钉扣在手心。\n");
		set("unwield_msg", "$N将手中的丧门钉放回装暗器的皮囊里。\n");
		set("base_unit", "枚");
		set("damage", 5);
		set("embed", 1);
		set("base_weight", 50);
		set("poison", "qtlh_poi");
		set("poison_number", 6);
	}
	set_amount(2);
	init_throwing(10);
	setup();
}
