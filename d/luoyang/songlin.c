
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֣����ܾ����ĵġ�һ�������͵�����������С���
����һ����ʯ����������ʯ��������
LONG);

  set("exits", ([ 
  "south":__DIR__"shanlu3",
  "west":__DIR__"caishichang",
  "east":__DIR__"songlin2",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

