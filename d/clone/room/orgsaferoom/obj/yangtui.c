
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("����", ({"yang tui","tui"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����ȡ�\n");
                set("unit", "��");
                set("value", 60);
                set("food_remaining", 30);
                set("food_supply", 80);
        }
}

