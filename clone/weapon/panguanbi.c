#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIM"�йٱ�"NOR, ({ "Panguan bi", "bi" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "����һֻ�����Ƴɵıʣ����ֱ��ں�ľ�·ǳ����С�\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һֻ$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ر��ʡ�\n");
	}
	init_sword(30);
	setup();
}
