
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С�Ե�");
  set ("long", @LONG
������һ��С�Ե꣬����ķ��˱��һ�������˸������ο͡�ʲ
ô���������������ӵȵȣ�������������ԣ�Ҳ�кܶ཭������ר����
�������������������ĵ�С��������ȥ��æ����ͣ���ŵ����㣬�㲻
����Щ���ˡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie2",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer3":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

