
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�������ǰ�������š����������������������Щ��
�֡��кܶ೵��������ȥ��һ�����ֵľ��󡣲�ʱ�д�ӵĹٱ�
����������߹����ŵ�·�ϵİ��ն���������ȥ��
LONG);

  set("exits", ([ 

  "east":__DIR__"ximen",
  "southwest":__DIR__"shalu1",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

