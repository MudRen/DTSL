
 
#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("��ǹ", ({"chang qiang", "qiang", "spear"}));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѳ�ǹ��ǹ���������⣮\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N�ó�һ��$n���������У�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_spear(40,100,100);
        setup();
}

