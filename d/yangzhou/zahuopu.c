
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ӻ���");
  set ("long", @LONG
���������ݵ�һ���ӻ��̡���ҵ��̿����Ѿã����������Ų�С��
������ÿ���������������˺ܶࡣ�����ϰ�����������æ��æȥ��
LONG);

  set("exits", ([ 
 "east":__DIR__"nanjishi",
        ]));
  set("objects",([
	  __DIR__"npc/zhu":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}


