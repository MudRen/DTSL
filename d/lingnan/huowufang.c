
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","���﷿");
  set ("long", @LONG
�������μұ��Ļ��﷿���μұ���������Ļ��ﶼ�������ﱣ�ܡ�
�μұ��Ļ����ܹ�������������Ż��
LONG);

  set("exits", ([ 

  "west":__DIR__"zhulin",
       ]));
  set("objects",([
	  __DIR__"npc/li":1,
	  ]));

  set("valid_startroom", 1);
 
  setup();
 
}

