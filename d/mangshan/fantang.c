
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
�������Ͼ��۵ķ��á�����ɢ�ҵط���һЩ������ȶ�����������
���ż����׷��������Ѿ��ܾ�û���������ˡ�
LONG);

  set("exits", ([ 

 "west":__DIR__"tingyuan",
         ]));
  set("objects",([
	  __DIR__"obj/rice":3,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

