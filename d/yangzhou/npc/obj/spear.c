#include <weapon.h>
inherit SPEAR;
void create()
{
        set_name("��ǹ", ({ "spear" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ǹ�������������е��⼣�߰ߡ�\n");
                set("value", 300);
                set("material", "����");
        }
        init_spear(20,90,90);
       set("wield_msg", "$N��$n�������������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");
        setup();
}
