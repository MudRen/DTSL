
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"dukou2"
#define TO __DIR__"dukou1"

#include "/std/shiproom.c"

void create ()
{
  set ("short","�ƺӶɿ�");
  set ("long", @LONG
�����ǻƺ������Ķɿڡ���ǰ�ǹ����Ļƺӣ�ֻ�м�������������
�ڶ����������ˡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"road8",
         ]));
set("outdoors","taiyuan");
  set("valid_startroom", 1);
  setup();
 
}

