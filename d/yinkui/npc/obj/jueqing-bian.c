
#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
	set_name(HIR"�����"NOR, ({ "jueqing bian","bian"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_save",1);
		set("long", "����һ������ޣ�͸©�������а����\n");
		set("value", 50);
		set("rumor",1);
		set("super",5);
		set("no_sell",1);
		set("material", "steel");
	}
	init_whip(170,180,180);


	set("wield_msg", "$N��ž����һ������һ��$n���������С�\n");
	set("unwield_msg", "$N�����е�$n�������䡣\n");


	setup();
}
