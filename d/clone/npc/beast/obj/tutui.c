
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("����", ({"tu tui","tui"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����ȡ�\n");
                set("unit", "��");
                set("food_remaining",50);
                set("food_supply", 50);
        }
}

