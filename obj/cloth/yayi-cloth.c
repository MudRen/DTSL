// yayi-cloth.c
//

#include <armor.h>

#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(BLU"���۷�"NOR, ({ "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ���ٸ����۵��·���\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 8);
             set("no_give", "����Ķ������ܸ��ˡ�\n");
       }
        setup();
}
