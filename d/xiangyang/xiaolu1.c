
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·���ϱ߾��ǳ����ˡ������Ե���Щ�����ˡ���ʱ��
��ӵĹٱ�����������߹����ŵ�·�ϵİ��ն���������ȥ������羰
������ɽˮ�续���������¡�
LONG);

  set("exits", ([ 
 "north":__DIR__"guanlu4",
 "southeast":__DIR__"xiaolu2",
 "east":"/d/jiujiang/xiaojing2",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

