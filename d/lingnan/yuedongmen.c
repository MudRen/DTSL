
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�¶���");
  set ("long", @LONG
�������¶��š������¶��ž����μұ�����ϰ��ĵط��ˡ�������
������������ϰ����ȵ��������������μұ��ĵ��Ӵ�������ͷ�󺹵�
���˹�����
LONG);

  set("exits", ([ 

   "northwest":__DIR__"zhengting",
   "east":__DIR__"liangting1",
   "southeast":__DIR__"caodi",
        ]));
  set("objects",([
	  __DIR__"npc/songshidao":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

