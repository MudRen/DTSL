
inherit ITEM;

void create()
{
        set_name("�������ȷ���", ({"staff book", "book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
   				set("long", "����һ�������������ȷ�������ѧ�鼮��\n");
        		set("material", "paper");
        		set("skill", ([
                        "name": "staff",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 1,
                        "max_skill": 100,
				]) );
        }
}

