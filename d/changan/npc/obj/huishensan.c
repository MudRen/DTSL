
inherit ITEM;
#include <ansi.h>
int do_fu(string arg);
void create()
{
   set_name("����ɢ", ({ "huishen san","san" }));
   set_weight(100);
   set("unit", "��");
   set("long","����һ��ר�Żָ������ҩ��.\n");
   set("value", 2000);
   
}


int do_eat(string arg)
{
	object me,ob;int i;
	ob=this_object();me=this_player();
	if(!arg||(arg!="san"&&arg!="huishen san"))
		return notify_fail("��Ҫ��ʲô?\n");
	if(me->query("eff_sen")==me->query("max_sen"))
		return notify_fail("��ľ���û���ܵ�����,��ʲôҩ��?\n");
    i=me->query("max_sen")-me->query("eff_sen");
	if(i<=10)
	me->add("eff_sen",i);
	else me->add("eff_sen",i/3); 
	message_vision("$N������һ��[����ɢ].\n",me);
	destruct(ob);
	return 1;
}