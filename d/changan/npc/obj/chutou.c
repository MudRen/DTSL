
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("��ͷ", ({ "chu tou","chu","tou" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѿ����൱��ͨ�ĳ�ͷ");
                set("value", 300);
                set("material", "wood");
        }
        init_staff(10,20,20);

      set("wield_msg", "$N��$n�������������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");

// The setup() is required.

        setup();
}
