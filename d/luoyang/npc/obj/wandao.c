
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIW"�䵶"NOR, ({ "wan dao","wan","dao","blade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���ӻ���״���䵶��\n");
		set("value",1500);
		set("material", "steel");
	}
	init_blade(60,100,100);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");

	setup();
}
