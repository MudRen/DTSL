
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·���������߾��ǳ����Ķ����ˣ����������ңң��
�������ĳ�ǽ����ʱ�����������������Գ۹����������ƺ���ȥͶ��
������ġ�����ս�����������������·���������Ǻ�̫ƽ��
LONG);

  set("exits", ([ 
"west":__DIR__"guanlu1",
"east":__DIR__"shanlu1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

