
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIG"�̷罣"NOR, ({ "bifeng jian", "jian","sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��[�̷罣]���������ǳ��������������Ϲŵ�������\n");
		set("value", 15000);
		set("no_save",1);
		set("super",5);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(40,120,120);
	setup();
}
