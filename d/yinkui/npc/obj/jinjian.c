// longsword.c ����

#include <weapon.h>
inherit SWORD;

#include <ansi.h>

void create()
{
	set_name(HIY"��"NOR, ({ "jin jian", "jian","sword"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ɫ��С�����������ǳ�С�����硣\n");
		set("value", 1500);
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(20,50,50);
	setup();
}
