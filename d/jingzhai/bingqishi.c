
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"������"NOR);
  set ("long", @LONG
�����ǴȺ���ի�ı����ҡ�������������ط��ż��ѱ������Ա���
��һ�����ӣ�д�ţ�����Ϊ����
LONG);

  set("exits", ([ 

  "north":__DIR__"suishilu3",
    ]));
  set("objects",([
	  __DIR__"obj/changjian":3,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

