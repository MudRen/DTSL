
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·���ϱ���һƬ���֡��������߿��Ե�̩ɽ��������
ͨ�����յĵ�·����������˲��Ǻܶࡣ
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu3",
 "southwest":__DIR__"shulin3",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

