
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����֡���ʱ��������ʿ��������һ����紵�����㲻
������˾��衣
LONG);

  set("exits", ([ 
  "northeast":__DIR__"xiaolu8",
  "southwest":__DIR__"shulin2",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

