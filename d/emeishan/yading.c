
#include <ansi.h>
inherit ROOM;

int do_claw(string arg);
void create ()
{
  set ("short","ɽ�¶�");
  set ("long", @LONG
������ɽ�µĶ������ܶ��˶�����������ҩ��
LONG);
   set("objects",([
	   __DIR__"obj/heshouwu":1,
	   ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_claw",({"pa","claw"}));
}

int do_claw(string arg)
{
	object me;
	me=this_player();
	if(!arg||arg!="down")
		return notify_fail("��Ҫ����������\n");
	message_vision("$N��ɽ������ȥ��\n",me);
	me->move(__DIR__"shanya");
	return 1;
}