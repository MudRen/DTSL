
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("����", ({"zhou zi","zhou","zi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����[��¥]����ɫ��.\n");
                set("unit", "��");
                set("value", 540);
                set("food_remaining", 50);
                set("food_supply", 80);
        }
}

