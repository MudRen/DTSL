
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һ��ɽ��������ں����ģ����ֲ�����ָ����ʱ���������
��ɳ����㲻��С��������
LONG);

  set("exits", ([ 

   "out":__DIR__"shanlu2",
   "northeast":__DIR__"shandong2",
   "east":__DIR__"shandong3",
         ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

