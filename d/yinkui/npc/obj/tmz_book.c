
inherit ITEM;

void create()
{
        set_name("��ħ��", ({"tianmozhen book", "book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "����һ��������ħ����鼮��\n");
        set("material", "paper");
        set("no_give",1);
        set("no_get",1);
        set("no_drop",1);
        set("no_steal",1);
        set("skill", ([
                        "name": "tianmo-zhen",
                        "exp_required":200000,
                        "sen_cost":50,
                        "difficulty":2,
                        "max_skill": 20,
]) );
        }
}

