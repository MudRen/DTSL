
#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(HIY"����"NOR, ({ "staff" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����ͨ�����ȡ�\n");
		set("value",500);
		set("material", "steel");
	}
	init_staff(60,170,170);

	set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�ŵ��˵��ϡ�\n");

	setup();
}
