
#include <ansi.h>
inherit ITEM;
int do_eat(string arg);
void create()
{
        set_name(HIR"�˲ι�"NOR, ({ "ren shen guo","guo" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
		set("long","����һö�˲ι�������������ҩ��Ҳ����ʳ�á�\n");
                set("value", 300);
				set("heal",([
					"heals":150,
					]));
       }

       setup();
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
	message_vision("$N������"+ob->name()+",����������ˬ���������̳����ޱȣ�\n",me);
	me->set("kee",me->query("max_kee"));
        me->set("eff_kee",me->query("max_kee"));
        me->set("gin",me->query("max_gin"));
        me->set("eff_gin",me->query("max_gin"));
        me->set("sen",me->query("max_sen"));
        me->set("force",me->query("max_force"));
	destruct(ob);
	return 1;
}
