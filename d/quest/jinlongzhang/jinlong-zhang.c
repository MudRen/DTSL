#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIY"��������"NOR, ({ "jinlong staff","staff" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500000000000);
		set("super",5);
		set("rumor",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_give",1);
		set("material", "iron");
		set("wield_msg", YEL"$N"+YEL+"���$n"+YEL+",�������л��˼��Ρ�\n"NOR);
		set("unequip_msg", "$N�����е�$n�ŵ��˵��ϡ�\n");
	}
	init_staff(150,400,400);
	setup();
}
