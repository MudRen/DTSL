

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIG"����"NOR, ({ "xiao"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���µ����\n");
                set("rumor",1);
		set("value", 9000);
		set("super",3);
		
	    set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ر���\n");
	}
        init_sword(120,120,120);
	setup();
}
