
#include <ansi.h>
inherit ROOM;

int do_enter(string arg);
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һɽ������˵����ʢ����ʯ������˶�������ɿ�������
������
LONG);
  set("objects",([
	  __DIR__"obj/iron":1,
	  ]));
 set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_enter",({"enter","zuan"}));
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	if(!arg||(arg!="��"&&arg!="hole"))
		return notify_fail("��Ҫ��������?\n");
	message_vision("$N��׼���ڣ�������ʹ����ȥ��\n",me);
	me->move(__DIR__"shilin");
	return 1;
}
