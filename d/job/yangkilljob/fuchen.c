
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("����", ({"fu chen", "fu","chen"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѵ�ʿ���õķ�����\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg","$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_whip(25,100,100);
        setup();
}

