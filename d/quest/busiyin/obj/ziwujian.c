

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIW"���罣"NOR, ({ "ziwu jian","jian","sword" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����а�̸��������ɵı�����\n");	
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ����С�\n");
	}
	init_sword(60,80,80);
	setup();
}
