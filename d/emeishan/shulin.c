
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֣�ÿ����ľ����ʮ���ɸߣ���Χ��İ������ʮ��
�ߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ��������ڵ�
˿��Ҳ�ޡ����ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���������һ��С
�ݡ�������һ�����¡�
LONG);

  set("exits", ([ 
 "north":__DIR__"wu",
 "west":__DIR__"xuanya",
 "south":__DIR__"shanlu2",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

