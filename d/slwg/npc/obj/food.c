
 
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
                set("value", 60);
                set("no_decay",1);
                set("food_remaining", 80);
                set("food_supply", 80);
                set("no_drop",1);
                set("no_get",1);
                set("no_give",1);
        }
}

