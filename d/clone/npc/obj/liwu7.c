
 
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
   set_name(HIY"Ԫ������"NOR, ({"zheng ji","ji"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����Ԫ���������������ǳ��óԡ�\n");
                set("unit", "��");
                set("no_sell",1);
                set("value", 60);
                set("no_decay",1);
                set("food_remaining",200);
                set("food_supply",200);
        }
}

