
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ݳǵı��š������Թ��������Ƿ������ֵĵط���������
�������˺ܶࡣ�����м����ٱ����ڼ�����������ˡ�
LONG);

  set("exits", ([ 
 "southwest":__DIR__"beidajie2",
 "north":"/d/outyang/guanlu4",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

