
#include <ansi.h>
inherit ROOM;

int do_enter(string arg);
void create ()
{
  set ("short","ʯ��");
  set ("long", @LONG
������һƬʯ�֡������ݲ��������ǹ�ʯ��᾵�ʯͷ��������һ
���ٲ���������Ϳ�����������������
LONG);

  set("exits", ([ 
 "north":__DIR__"pubu",
 "south":__DIR__"caodi1",
       ]));
   set("outdoors","emeishan");
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
	message_vision("$N��׼һ�����ڣ�������ʹ����ȥ��\n",me);
	me->move(__DIR__"hole");
	return 1;
}