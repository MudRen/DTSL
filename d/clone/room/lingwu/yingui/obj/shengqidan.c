
 
inherit ITEM;
int do_eat(string arg);
void create()
{
   set_name("ʥ����", ({"sheng qi dan","dan"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���Ƕ����ɵ���������[ʥ����]��\n");
                set("unit", "ö");
                set("value", 1000);         
        }
}

void init()
{
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object me,ob;
	me=this_player();ob=this_object();
	if(!arg||ob!=present(arg,me))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N������"+ob->name()+"\n",me);
	me->receive_curing("kee",50+random(10));
	destruct(ob);
	return 1;
}
 