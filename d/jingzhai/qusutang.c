
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"ȥ����"NOR);
  set ("long", @LONG
�����ǴȺ���ի��ȥ���á����õĺ����ǴȺ���ի�ĵ��ӿ���ȥ��
�������֣���Ҫʱ�̽���ȥ�׶��֡�����ׯ�����£������е�����Ҳ��
����ࡣ
LONG);

  set("exits", ([ 

  "west":__DIR__"wuwangdian",
  "east":__DIR__"wuyutang",
  "south":__DIR__"wutantang",
  "north":__DIR__"wuchentang",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

