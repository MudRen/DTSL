
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������������С��������߾���ˮ�����ˡ��кܶ����������Ϲ�
�������������ǵķ�⡣
LONG);

  set("exits", ([ 
  
  "east":__DIR__"shanjingju",
  "northwest":__DIR__"baihujie2",
  "southup":__DIR__"baihuqiao",

         ]));
  set("objects",([
	  __DIR__"npc/rongjiaojiao":1,
	  ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

