
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֡������Ѿ��Ǻ��Ͼ��ء���֪��������û��ǿ����
��ӿ���ǰ���ĽŲ���
LONG);

  set("exits", ([ 
 "east":"/d/xingyang/dadao4",
 "west":__DIR__"shulin6",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

