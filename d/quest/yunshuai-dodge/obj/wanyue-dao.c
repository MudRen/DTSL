
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIY"���µ�"NOR, ({ "wanyue dao","dao","blade"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_save",1);
		set("long", "����һ�����µ����������Ž�ɫ�Ĺ�â��\n");
		set("value", 50);
		set("rumor",1);
		set("super",5);
		set("no_sell",1);
		set("material", "steel");
	}
	init_blade(170,180,180);


	set("wield_msg", "$N�����س��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뵶�ʡ�\n");
	setup();
}
