
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @long
��������֣��м��ǻʵ۳�Ѳ����������·��������ֲ�����Ʒ��
����ľ����������ȷ��һ�����߷緶���������������Ķ��Ҿ�¥��
long);

  set("exits", ([   
      "south":__DIR__"nanjie1",
      "north":__DIR__"tianjie3",
      "west":__DIR__"dongjia-jiulou",
  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

