
#include <weapon.h>
//#include <ansi.h>
inherit FORK;

void create()
{
	set_name("�ֲ�", ({ "fork" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ������ֲ档\n");
		set("value",500);
		set("material", "steel");
	}
	init_fork(15,90,90);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�ŵ����ϡ�\n");

	setup();
}
