
#include <weapon.h>
//#include <ansi.h>
inherit BLADE;

void create()
{
	set_name("�̵�", ({ "duan dao","dao","blade" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���ǰѶ̵��������ޱȡ�\n");
		set("value",100);
		set("material", "steel");
	}
	init_blade(20,60,60);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�������ĵ��ʡ�\n");

	setup();
}
