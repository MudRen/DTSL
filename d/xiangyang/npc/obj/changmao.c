
#include <weapon.h>
//#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name("��ì", ({ "chang mao","mao","spear" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�˳�ì��ǹͷѩ�׳�����\n");
		set("value",600);
		set("material", "steel");
	}
	init_spear(20,90,90);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������У�$n��ǹ����������������¡�\n");
	set("unwield_msg", "$N�����е�$n�ŵ����ϡ�\n");

	setup();
}
