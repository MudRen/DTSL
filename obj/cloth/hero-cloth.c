// hero-cloth.c ��ɫӢ���

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(CYN"��ɫӢ���"NOR, ({"cloth", "hero cloth"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("long", "һ������ɫ��Ӣ��멡�\n");
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
