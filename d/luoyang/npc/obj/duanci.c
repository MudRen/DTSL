
#include <weapon.h>
//#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name("�̴�", ({ "dagger" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�Ѷ̴̣�С����\n");
		set("value",500);
		set("material", "steel");
	}
	init_dagger(15,60,60);

	set("wield_msg", "$N��ৡ���һ���ӻ��г��һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");

	setup();
}
