#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIR"͵�콣"NOR, ({ "sword","jian" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("super",3);
		set("no_save",1);
		set("rumor",1);
		set("material", "iron");
		set("wield_msg", "$N���$n,��ʱ��Χ���˸����硣\n");
		set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword(225,180,180);
	setup();
}
