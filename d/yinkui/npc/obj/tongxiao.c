
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIB"ͭ��"NOR, ({ "tong xiao","xiao"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_save",1);
		set("long", "����һ��ͭ�������滭��һЩ�Źֵ�ͼ����\n");
		set("value", 50);
		set("rumor",1);
		set("super",5);
		set("no_sell",1);
		set("material", "steel");
	}
	init_sword(170,180,180);


	set("wield_msg", "$N�����س��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");


	setup();
}
