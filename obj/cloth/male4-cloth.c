// male4-cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( CYN "�̴�װ" NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ���������Ķ̴�װ��\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 1);
              set("no_give", "����Ķ������ܸ��ˡ�\n");

        }
        setup();
}

