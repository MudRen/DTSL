
#include <ansi.h>
inherit ITEM;
int do_chakan(string arg);
void create()
{
   set_name("ͨ�龵", ({"tongling jing","jing"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ǿ��Բ鿴����������ͨ�龵��\n");
                set("unit", "��");
                set("treatures",1);
        }
}

void init()
{
	add_action("do_chakan","chakan");
}

int do_chakan(string arg)
{
	object me,ob;
	me=this_player();
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("��Ҫ�鿴˭��\n");
	message_vision(HIR"$N��$n��ǰ����[ͨ�龵]�������������ֳ�һ�����֡�\n"NOR,me,ob);
	tell_object(me,"ͨ�龵�����㣺"+ob->name()+"�Ѿ�������"+chinese_number(ob->query("deadtimes"))+"��\n");
	tell_room(environment(me),"ͨ�龵ž��һ������ˣ�\n");
	destruct(this_object());
	return 1;
}
