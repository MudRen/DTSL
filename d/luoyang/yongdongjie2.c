
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
������������������֡�������һ��Ǯׯ����������������������
���⡣�����߿��Ե������ʹ������š�
LONG);

  set("exits", ([ 
  

  "north":__DIR__"yongdongjie3",
  "east":__DIR__"qianzhuang",
  "south":__DIR__"huangchengnan",
         ]));
  set("objects",([
	  __DIR__"npc/xiake":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

