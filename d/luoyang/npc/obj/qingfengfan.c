
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("��緹", ({"qingfeng fan","fan","baihuajian_quest_obj"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����������緹��\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 60);
                set("food_supply", 50);
        }
}

