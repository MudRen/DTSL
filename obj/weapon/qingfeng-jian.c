// ��潣��

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("��潣", ({ "qingfeng jian", "jian" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����[Ӱ�Ӵ̿�]�����ӵ�������\n");
		set("value", 1500);
		set("super",4);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(30,120,120);
	setup();
}
