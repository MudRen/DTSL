
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("��֭��ζ��", ({"fish","yu"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����[��¥]����ɫ��,��˵����������ζ����\n");
                set("unit", "��");
                set("value", 600);
                set("food_remaining", 50);
                set("food_supply", 80);
        }
}

