
#include <ansi.h>
inherit ROOM;

int do_jump(string arg);
void create ()
{
  set ("short","ˮ̶");
  set ("long", @LONG
������һ��ˮ̶��̶ˮ�峺���ף�ˮ�µĶ��������������������
����Կ���Զ�������¡�
LONG);

  set("exits", ([ 
 "south":__DIR__"shanlu3",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_jump",({"jump","tiao"}));
	add_action("do_qian","qian");
}

int do_jump(string arg)
{
	object me;
	me=this_player();
	if(!arg||(arg!="̶"&&arg!="ˮ̶"))
		return notify_fail("��Ҫ����������\n");
	message_vision("$Nһ�����ӳ�̶����ȥ��\n",me);
	me->move(__DIR__"tandi");
	return 1;
}
int do_qian(string arg)
{
	object me;
	me=this_player();
	
	if(!arg||(arg!="ˮ"&&arg!="shui"))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$Nһ�����ӳ�̶����ȥ��\n",me);
	me->move("/d/clone/room/iron/room3");
	return 1;
}