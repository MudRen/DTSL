
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·���ϱ߾��ǳɶ��ı����ˡ���������˽���������
������Щ�����ˡ�
LONG);

  set("exits", ([ 
  "northeast":__DIR__"guanlu3",
  "southwest":"/d/chengdu/dabeimen",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

