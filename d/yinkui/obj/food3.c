
 
inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
   set_name(HIB"����"NOR, ({"qing she","she"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����ߣ���ҩ���н��ݹ�������ʳ�á�\n");
                set("unit", "��");
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

