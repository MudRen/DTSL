
#include <weapon.h>
//#include <ansi.h>
inherit STAFF;

void create()
{
	set_name("����", ({ "gang zhang","zhang","staff" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����ͨ�ĸ��ȡ�\n");
		set("value",600);
		set("material", "steel");
	}
	init_staff(20,150,150);

	set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�ŵ����ϡ�\n");

	setup();
}
