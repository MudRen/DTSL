
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·���ϱ������롣�����˼�����������û��ʲô�ˡ���
����Ҫ·��������ǽ����С���˵���ﾭ����ǿ����û��
LONG);

  set("exits", ([ 
  "northeast":__DIR__"guanlu2",
  "northwest":__DIR__"luanshigang",
  "southup":__DIR__"shanlu2",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

