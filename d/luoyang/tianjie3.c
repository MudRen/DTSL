
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @long
��������֣��м��ǻʵ۳�Ѳ����������·��������ֲ�����Ʒ��
����ľ����������ȷ��һ�����߷緶��
long);

  set("exits", ([   
      "south":__DIR__"tianjie4",
      "north":__DIR__"xinzhongqiao3",
      "east":__DIR__"shennvdi1",
      "west":__DIR__"luoshuidi3"
  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

