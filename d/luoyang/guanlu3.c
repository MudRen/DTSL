
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·���ϱ߾��ǳɶ��ˡ���������˽�������������Զ
���������ֵ�������
LONG);

  set("exits", ([ 
  "northeast":__DIR__"shashilu2",
  "southwest":__DIR__"guanlu4",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

