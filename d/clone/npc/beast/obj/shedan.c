
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("�ߵ�", ({"she dan","dan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һö�ߵ���\n");
                set("unit", "ö");
                set("food_remaining",40);
                set("food_supply", 40);
        }
}

