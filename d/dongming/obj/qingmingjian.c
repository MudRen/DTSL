
#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
	set_name(HIG"���齣"NOR, ({ "qingming jian","sword","jian" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������������ഫ�ı�����\n");
		set("super",5);
		set("rumor",1);
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(60,150,150);
	setup();
}
