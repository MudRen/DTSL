
#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIG"������"NOR, ({"biyu zhang", "zhang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ɫ�Ĺ��ȣ�\n");
                set("value", 500);
                set("no_save",1);
                set("rumor",1);
                set("material", "iron");
                set("wield_msg","$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(160,200,200);
        setup();
}

