
#include <ansi.h>
inherit ITEM;
int do_eat(string arg);
void create()
{
        set_name(HIR"人参果"NOR, ({ "ren shen guo","guo" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
		set("long","这是一枚人参果，可以用来炼药，也可以食用。\n");
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
		return notify_fail("你要吃什么？\n");
	message_vision("$N吞下了"+ob->name()+",觉得神清气爽，丹田立刻充沛无比！\n",me);
	me->set("kee",me->query("max_kee"));
        me->set("eff_kee",me->query("max_kee"));
        me->set("gin",me->query("max_gin"));
        me->set("eff_gin",me->query("max_gin"));
        me->set("sen",me->query("max_sen"));
        me->set("force",me->query("max_force"));
	destruct(ob);
	return 1;
}
