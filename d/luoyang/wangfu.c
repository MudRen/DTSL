
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�����丮"NOR);
  set ("long", @LONG
����������������������������������������ܣ�ƽ���˵Ȳ���
������ڡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"luoshenjie3",
  "enter":__DIR__"wangfu_neiting",
  "northeast":"/d/clone/room/cityroom/luoyang",

         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

/*int valid_leave(object me,string dir)
{
	if((!me->query("shili")||(string)me->query("shili")!="wang")&&dir=="enter"&&!wizardp(me))
		return notify_fail("���洫������������������Ȼ���Ǳ��������ˣ��Ͳ�Ҫ������!\n");
	return ::valid_leave(me,dir);
}*/
