
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
������һ����ʯ·��������������ķ�ש����������Ե���ܼ���
������ҡ��м���Ѿ���������������
LONG);

  set("exits", ([ 
	  "east":__DIR__"feiniao_yuan",
	  "north":__DIR__"woshi2",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

