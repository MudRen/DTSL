
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�����������룬����ĵ�·��Щ���ˡ��ϱ���һ
Ƭ���֣��������ǳ�ï�ܡ�
LONG);

  set("exits", ([ 
  "north":__DIR__"shanlu5",
  "southwest":__DIR__"shulin1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

