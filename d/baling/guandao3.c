
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ�ٵ�");
  set ("long", @LONG
����������·���ϱ��ǰ���ı��š����������������������Щ��
�֡������������кܶ೵��һ�����ֵľ��󡣲�ʱ�зɳۿ��������
���ܹ����ŵ�·�ϵİ��ն���������ȥ��
LONG);

  set("exits", ([ 

  "south":__DIR__"guandao2",
  "north":__DIR__"guandao4",
  "northwest":__DIR__"yingmen",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

