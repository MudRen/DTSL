
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("�׷�", ({"rice"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����׷���\n");
                set("unit", "��");
                set("value", 10);
                set("food_remaining", 20);
                set("food_supply", 50);
        }
}

