// �

#include <weapon.h>
inherit JIAN;

void create()
{
	set_name("�", ({"jian"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ﵡ�\n");
		set("value", 1500);
		
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_jian(20,100,100);
	setup();
}
