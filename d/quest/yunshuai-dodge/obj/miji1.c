
inherit ITEM;

void create()
{
        set_name("����ӥ���衷", ({"jiuying-dodge book", "book","shu"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "��");
          set("long", "����һ����������ӥ���衷����ѧ�鼮��\n");
          set("material", "paper");
          set("no_give",1);
          set("no_steal",1);
          set("skill", ([
                        "name": "jiuying-dodge",
                        "exp_required": 100,
                        "sen_cost": 60,
                        "difficulty":10,
                        "max_skill":100,
          ]));
        }
}

