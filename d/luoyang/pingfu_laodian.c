
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ƽ���ϵ�");
  set ("long", @LONG
������һ�������̣���������Ϊ���������С�㶼�����������ϣ�
����Ѭ˯�ʺͱ��졣���ﻹ�м۸񼫸ߵļ�Ʒ���������Ƴɵ����ϣ�
����ֻ����Ǯ�˼Ҳ������ġ�
LONG);

  set("exits", ([ 
  "west":__DIR__"nanjie4",
         ]));
  set("objects",([
	  __DIR__"npc/xiangliao_laoban":1,
	  ]));
  set("valid_startroom", 1);
  set("resource/water",1);
  setup();
 
}

