
 
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
   set_name(YEL"����"NOR, ({"dazao"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һö���档\n");
                set("unit", "ö");
                set("value", 20);
                set("no_decay",1);
                set("food_remaining", 10);
                set("food_supply", 10);
        }
}

