
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
�����Ƿ��������Ĳ�԰�����﹩Ӧ������������ʳ��ֻ����������
������������ֵء�ÿ���＾�ջ񼾽ڣ����ﶼ��һ�ɷ��յľ�ɫ��
LONG);

  set("exits", ([ 
	  "north":__DIR__"xiuxishi",
	  "east":__DIR__"caodi2",
	  "south":__DIR__"chufang",
    ]));
set("outdoors","feima");
  set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

