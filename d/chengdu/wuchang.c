
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
�����Ǹ����䳡�����𱤵ĵ���ƽʱ����������ϰ���ա�ֻ������
�����������������������������Ŭ����ϰ�䣬��ʱ�������䳡������
�
LONG);

  set("exits", ([ 
	  "north":__DIR__"xiuxishi",
	  "south":__DIR__"caodi4",
	  "east":__DIR__"bingqishi",
        ]));
  set("objects",([
	  __DIR__"npc/dizi3":1,
	  ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
