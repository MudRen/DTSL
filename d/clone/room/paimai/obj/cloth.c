#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"��װ"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "�����Ͽ��Կ�����������ľ�ֻ����ʦ�ɡ�\n");
                set("material", "cloth");
                set("value", 0);
                set("armor_prop/armor", 3);
              set("no_give", "����Ķ������ܸ��ˡ�\n");

        }
        setup();
}

