
inherit ITEM;
#include <ansi.h>
int do_fu(string arg);
void create()
{
   set_name("回神散", ({ "huishen san","san" }));
   set_weight(100);
   set("unit", "颗");
   set("long","这是一种专门恢复精神的药物.\n");
   set("value", 2000);
   
}


int do_eat(string arg)
{
	object me,ob;int i;
	ob=this_object();me=this_player();
	if(!arg||(arg!="san"&&arg!="huishen san"))
		return notify_fail("你要吃什么?\n");
	if(me->query("eff_sen")==me->query("max_sen"))
		return notify_fail("你的精神没有受到损伤,吃什么药啊?\n");
    i=me->query("max_sen")-me->query("eff_sen");
	if(i<=10)
	me->add("eff_sen",i);
	else me->add("eff_sen",i/3); 
	message_vision("$N服下了一颗[回神散].\n",me);
	destruct(ob);
	return 1;
}