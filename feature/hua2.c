inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"hua", "wuming"}));
        set("unit", "��");
	set("long", "����һ������С��,������С,ȴʮ��������\n");
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
if(arg=="hua") 
{
this_player()->unconcious();
this_player()->add("potential",50);
destruct(this_object());
}
return 1;
}
