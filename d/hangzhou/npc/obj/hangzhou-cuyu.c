
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("���ݴ���", ({"hangzhou cuyu","yu","fish","cuyu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���Ǻ��ݵ���ɫ��[���ݴ���]��\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 30);
                set("food_supply", 50);
        }
}

