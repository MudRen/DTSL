#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIB"����"NOR, ({ "tie shan","shan"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",100);
		set("material", "iron");
		set("wield_msg", "$N���$n,���˼���,�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(35,30,30);
	setup();
}
