
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIC"ɫ�ս�"NOR, ({ "sekong jian", "jian","sword" }));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("rumor",1);
		set("no_save",1);
		set("long", "����һ��������������š�ɫ�ա����֡�\n");
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(200,300,300);
	setup();
}
