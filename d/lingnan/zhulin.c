
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǹ����֡�����ڽڣ������ڡ������ǻ��﷿���������߾�
�Ǻ��ˡ�
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaoqiao1",
 "east":__DIR__"huowufang",
 "south":__DIR__"houbao",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

