

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(GRN"������"NOR, ({ "bawang dao", "bawang","dao","blade" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ǵ���[�Ե�]��ɽ��ʹ�õĵ�����˵�����ޱȡ�\n");
		set("value", 15000);
 set("no_save",1);
	    set("super",4);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(30,150,150);
	setup();
}
