

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(HIY"����ͭ��"NOR, ({ "dujiao tongren","tongren" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ͭ�ˡ�\n");	
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N�Ӻ󱳳��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ر���\n");
	}
	init_staff(60,150,150);
	setup();
}
