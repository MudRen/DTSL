
 
inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
   set_name(BLU"��Ы��"NOR, ({"xie zi","xie"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һֻ��Ы�ӣ���ҩ���н��ݹ�������ʳ�á�\n");
                set("unit", "ֻ");
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

