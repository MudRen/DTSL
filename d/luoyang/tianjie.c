
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
      "south":__DIR__"tianjie2",
      "north":__DIR__"beijie1",
      "east":__DIR__"chaixinpu"
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

