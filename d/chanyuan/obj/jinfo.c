
 
inherit ITEM;

#include <ansi.h>

void create()
{
   set_name(HIY"���"NOR, ({"jin fo","fo"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��С��𣬿�������ֵǮ��\n");
                set("unit", "��");
                set("value", 1000000000000000);
                set("no_sell",1);
                set("nogive_player",1);
                set("bai_butan_quest",1);
        }
}

