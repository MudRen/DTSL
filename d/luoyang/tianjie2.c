
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
      "south":__DIR__"xinzhongqiao1",
      "north":__DIR__"tianjie",
      "east":__DIR__"xiangwangjie1",
      "west":__DIR__"luoshenjie3"
  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

