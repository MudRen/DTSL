
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
�����Ǵ��ɽ��ɽ������������ȥ��ֻ�����Ƕ��͵�ɽ�¡�������
һ����ɽ��·������ĵ�·�ǳ��վ����㲻��С��������
LONG);

  set("exits", ([ 

   "eastdown":__DIR__"shanjiao",
   "west":__DIR__"shanlu4",
   "northup":__DIR__"shanlu1",
   "south":__DIR__"shanlu2",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

