
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·���������߾��ǳ����������ˣ����������ңң��
�������ĳ�ǽ����ʱ�����������������Գ۹����������ƺ���ȥͶ��
������ġ�����ս�����������������·���������Ǻ�̫ƽ��
LONG);

  set("exits", ([ 
"northwest":__DIR__"mingdemen",
"south":__DIR__"guanlu4",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

