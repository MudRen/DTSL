
#include <ansi.h>
inherit ROOM;


void create ()
{
set ("short","�����");
  set ("long", @LONG
�����������ı��֡����ϵ��˺��٣��Ե���Щ���塣������һ�Ҳ�
��꣬�����ſڿ������������塣�м�������վ�����������̸����
���µ����ơ�
LONG);

  set("exits", ([ 
 "north":__DIR__"beidajie3",
 "south":__DIR__"beidajie1",
 "east":__DIR__"caifengdian",
        ]));
  set("objects",([
	  __DIR__"npc/butou":1,
	  __DIR__"npc/old":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

