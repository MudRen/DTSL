
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"��԰"NOR);
  set ("long", @LONG
����������Ժ�Ļ�԰�ˡ�������һ�������㷼������������ݡ�ÿ
�������������ӵ��������ﲻ������������ÿ���˶������й����۵ġ�
LONG);

  set("exits", ([ 
	  "out":__DIR__"manqingyuan",
	  "west":__DIR__"xilou",
          "north":__DIR__"beilou",
          "south":__DIR__"nanlou",
  ]));
   set("objects",([
	   __DIR__"npc/shangxiu-fang":1,
	   ]));
   set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}
