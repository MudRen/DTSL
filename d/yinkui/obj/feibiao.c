// dart.c

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
	set_name(HIY"������"NOR, ({ "fei biao","biao","dart" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","���������ɵ�����������\n");
		set("unit", "Щ");
		set("base_unit", "ö");
		set("base_weight",40);
		set("throwing",1);
		set("value", 5);
		set("no_save",1);
	}
	set_amount(1);
	init_throwing(10,10,10);
	setup();
}

int is_get_of(object ob,object obj)
{
   return 1;
}
