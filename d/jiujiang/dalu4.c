
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����Ǹ�����·�����߾������ݵ������ˣ�������������������
�ֵ�������
LONG);

  set("exits", ([ 

  "southeast":"/d/yangzhou/ximen",
  "northwest":__DIR__"dalu3",
  
         ]));
  set("objects",([
	  __DIR__"npc/xiake":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

