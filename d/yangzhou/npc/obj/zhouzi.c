
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("������", ({"jiang zhouzi","zhouzi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������,��˵�õĽ��Ѿ�������ʮ���ˡ�\n");
                set("unit", "��");
                set("value",80);
                set("food_remaining",20);
                set("food_supply", 40);
        }
}

