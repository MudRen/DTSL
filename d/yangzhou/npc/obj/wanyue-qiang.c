
#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name(HIW"������ǹ"NOR, ({ "spear" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���ǹ��ǹ�����䣬�����[����]֮�ơ�\n");
		set("value", 4000);
		set("material", "steel");
	}
	init_spear(80,120,120);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�ŵ��˵��ϡ�\n");

	setup();
}
