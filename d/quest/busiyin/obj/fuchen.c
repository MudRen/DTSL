

#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
	set_name("����", ({ "fu chen","fu","chen" }));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������\n");	
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N���$n���˼��Σ��������С�\n");
		set("unwield_msg", "$N�����е�$n��ر���\n");
	}
	init_whip(20,60,60);
	setup();
}
