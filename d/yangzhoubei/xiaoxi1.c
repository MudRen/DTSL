
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","СϪ");
  set ("long", @LONG
����һ��СϪ��Ϫˮ�峺���������ǰ�����������㲻ʱ���Կ���
��Ұ�õ�С�������Աߺ�ˮ��
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu1",
 "south":__DIR__"shulin1",
        ]));
  set("objects",([
        __DIR__"npc/yetu":1
      ]));
  set("resource/water",1);
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

