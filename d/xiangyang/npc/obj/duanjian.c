
#include <weapon.h>
//#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("�̽�", ({ "duan jian","jian","sword" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���ǰѶ̽��������ޱȡ�\n");
		set("value",500);
		set("material", "steel");
	}
	init_sword(20,60,60);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�������Ľ��ʡ�\n");

	setup();
}
