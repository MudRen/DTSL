
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
������һ��ɳʯ·�������������Щ���ȡ�ͷ����һЩ��֪����С
����������ȥ�����ܴ����ܲ����ʻ��̲��������֡�
LONG);

  set("exits", ([ 

  "north":__DIR__"tulu6",
  "southeast":__DIR__"shalu2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

