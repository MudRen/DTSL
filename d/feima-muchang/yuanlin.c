
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"԰��"NOR);
  set ("long", @LONG
�����Ǹ�С԰�֡�����ľ�ɫ������������ɽ��ʯ��ᾣ���������
���������������������۹����֮�����������˺ܶ���ʻ�������Ʒ
�ַ��࣬����ɫ���������������ޡ����һ�����ɫ����õ���һ������
������������Ŀ.
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"qingshilu3",
	  "southwest":__DIR__"xiaolu3",
	  "east":__DIR__"yuedongmen",
	  "north":__DIR__"qingshilu4",
	  "southeast":__DIR__"qingshilu2",
         ]));
  set("objects",([
	  __DIR__"npc/liangzhi":1,
	  ]));
set("outdoors","feima");
  
  set("valid_startroom", 1);
  setup();
 
}

