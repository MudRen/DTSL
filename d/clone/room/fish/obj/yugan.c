// staff.c : Gun zi

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("���", ({ "yu gan","gan" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",200);
	        			set("material", "wood");	        			
        }
        init_staff(10,20,20);
        set("weapon_prop/yugan",1);

        set("wield_msg", "$N��$n�������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");

        setup();
}
