
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("Ҭ��", ({"ye zi","ye","zi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��Ҭ�ӡ�\n");
                set("unit", "��");
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}
