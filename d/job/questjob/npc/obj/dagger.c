
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name("����̴�", ({ "baiyu duanci","duanci","dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_save",1);
		set("long", "����һ�Ѱ���̴̡�\n");
		set("value", 50);
		set("material", "steel");
	}
	init_dagger(30,100,100);


	set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");


	setup();
}
