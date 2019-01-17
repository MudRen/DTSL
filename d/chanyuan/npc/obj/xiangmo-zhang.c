
#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIY"降魔杖"NOR, ({"xiangmo zhang","zhang","staff"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "此杖名为降魔杖，乃净念禅院的阵寺宝兵器。\n");
                set("no_save",1);
                set("no_sell",1);
                set("rumor",1);
                set("material", "iron");
                set("wield_msg","$N拿起$n，挥舞了几下，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(180,200,200);
        setup();
}

