
inherit ITEM;

void create()
{
        set_name("������ȭ�š�", ({"unarmed book", "book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
   set("long", "����һ������������ȭ�š�����ѧ�鼮��\n");
        set("material", "paper");
        set("skill", ([
                        "name": "unarmed",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 1,
                        "max_skill":100,
]) );
        }
}

