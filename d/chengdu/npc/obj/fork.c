
#include <weapon.h>
inherit FORK;

void create()
{
	set_name("��ǹ", ({ "fork"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ǹ��\n");
		set("value", 1500);
		
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n����������\n");
	}
	init_fork(20,120,120);
	setup();
}
