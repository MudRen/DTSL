
inherit ITEM; 
inherit F_FOOD;

void create()
{
   set_name("��ͷ", ({"mantou"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ͷ��\n");
                set("unit", "��");
                set("value",1);
                set("food_remaining", 20);
                set("food_supply", 10);
        }
}

