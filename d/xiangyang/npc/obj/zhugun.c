//���

#include <weapon.h>
inherit STICK;

void create()
{
	set_name("���", ({ "zhugun", "zhu","gun" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����,�������˶��������������\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_stick(20,30,30);
	setup();
}
