
 
inherit ITEM;
inherit F_FOOD;
int do_eat(string arg);
void create()
{
   set_name("�㽶", ({"banana"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ���㽶���ܺóԵġ�\n");
                set("unit", "��");
                set("value", 600);
                set("food_supply", 30);
		call_out("rid",120,this_object());
        }
}

void init()
{
	add_action("do_eat","eat");
}
int do_eat(string arg)
{
	int food_s;
	object me,ob;object pi;
    me=this_player();ob=this_object();
	if(!arg||arg!="banana")
		return notify_fail("��Ҫ��ʲô��\n");
	if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
     return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
    food_s=ob->query("food_supply");
	ob->add("food_supply",-5);
	me->add("food",10);
	message_vision("$N����"+ob->name()+"���˼���\n",me);
	if(ob->query("food_supply")<=0)
	{
		//pi=new(__DIR__"pi");
		//pi->move(environment(me));
		destruct(ob);
		return 1;
	}
	return 1;
}

void rid(object ob)
{
	destruct(ob);
	remove_call_out("rid");
	return;
}