
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ԭ");
  set ("long", @LONG
������һƬһ���޼ʵĲ�ԭ���м�������������������������
�����ķ���������Զ�ˣ�����������ۿ��ޱȣ�������Ƿ�����������
�ԡ�
LONG);

  set("exits", ([ 
  "southeast":__DIR__"shanlu2",
  "northwest":__DIR__"shanlu3",
        ]));
  set("objects",([
	  __DIR__"npc/mafu":1,
	  __DIR__"npc/horse":1,
	  ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

