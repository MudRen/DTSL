
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·���μұ��Ѿ����������Ŀ����ˡ���˵�����ϣ��μ�
���ǳ���һ�������ǳ�͢Ҳ�κ����ǲ��á�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu3",
 "southwest":"/d/lingnan/dalu2",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

