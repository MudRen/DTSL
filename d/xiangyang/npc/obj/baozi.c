
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("����", ({"bao zi","bao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�������ݰ��ӵ����ɫ,�����ݷǳ�������\n");
                set("unit", "��");
                set("value", 60);
                set("food_remaining", 30);
                set("food_supply", 30);
        }
}

