
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·��������ǽ��������ϵĽ����ˡ��ϱ߾��������ˡ�
���ϵĵ�һ�����������μұ��ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"tulu2",
 "southwest":__DIR__"shanlu2",
 "northwest":"/d/baling/shashilu2",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

