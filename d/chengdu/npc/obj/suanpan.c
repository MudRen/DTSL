
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("����", ({"suan pan", "suan","pan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������̣���һ�ֶ��ű�����\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(10,80,80);
        setup();
}

