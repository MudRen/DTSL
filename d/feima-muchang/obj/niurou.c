
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("ţ��", ({"niu tui","tui"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����������ţ�ȡ�\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

