
#include <weapon.h>
//#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name("������", ({ "hammer" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�Ѵ���������������Щ���ء�\n");
		set("value", 1200);
		set("material", "steel");
	}
	init_hammer(50,160,160);

	set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�ŵ��˵��ϡ�\n");

	setup();
}
