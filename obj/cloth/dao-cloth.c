// dao-cloth.c ��ɫ����

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(CYN"��ɫ����"NOR, ({"pao", "cloth", "dao pao"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("long", "һ������ͨͨ���಼���ۡ�\n");
		set("material", "cloth");
		set("armor_prop/armor", 2);
             set("no_give", "����Ķ������ܸ��ˡ�\n");
	
	}
	setup();
}
