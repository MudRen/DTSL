
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"dukou1"
#define TO __DIR__"dukou2"

#include "/std/shiproom.c"

void create ()
{
  set ("short","�ƺӶɿ�");
  set ("long", @LONG
�����ǻƺӶ����Ķɿڡ���ǰ�ǹ����Ļƺӣ�ֻ�м�������������
�ڶ����������ˡ�
LONG);

  set("exits", ([ 

  "east":__DIR__"road3",
         ]));
set("outdoors","taiyuan");
  set("valid_startroom", 1);
  setup();
 
}

