
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("ذ��", ({ "dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "steel");
	}
	init_dagger(5,20,20);

	set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");

	setup();
}
