
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
���������������С�������ˮ���š��������ߣ����ǰ׻����ˡ���
����������ϱ����ֵ�������
LONG);

  set("exits", ([ 
  
	  "west":__DIR__"dangpu",
  "northup":__DIR__"baihuqiao",
  "southeast":__DIR__"baihumen",

         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

