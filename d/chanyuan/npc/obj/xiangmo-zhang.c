
#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIY"��ħ��"NOR, ({"xiangmo zhang","zhang","staff"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������Ϊ��ħ�ȣ��˾�����Ժ�����±�������\n");
                set("no_save",1);
                set("no_sell",1);
                set("rumor",1);
                set("material", "iron");
                set("wield_msg","$N����$n�������˼��£��������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(180,200,200);
        setup();
}

