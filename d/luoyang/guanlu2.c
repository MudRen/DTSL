
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�������������ŵĹ�·�������Ѿ����˽����ˡ���ʱ��������ʿ��
�����ϱ߾��������ˡ�
LONG);

  set("exits", ([ 
  "northeast":__DIR__"guanlu1",
  "southwest":__DIR__"shanlu1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

