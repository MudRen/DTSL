
inherit ITEM;

void create()
{
        set_name("������ذ����", ({"dagger book", "book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
   				set("long", "����һ������������ذ��������ѧ�鼮��\n");
        		set("material", "paper");
        		set("skill", ([
                        "name": "dagger",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 1,
                        "max_skill": 100,
				]) );
        }
}

