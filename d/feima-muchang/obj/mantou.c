
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("��ͷ", ({"man tou","tou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ѩ�׵���ͷ��\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 10);
                set("food_supply", 40);
        }
}
