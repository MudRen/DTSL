
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����Ǹ�����·����������˽���������������Щ�����ˡ�����
����ȥ����������ԼԼ�������ݳ��ˡ�
LONG);

  set("exits", ([ 

  "east":__DIR__"dalu2",
  "southwest":"/d/yangzhou/xiaolu1",
  
         ]));
  set("objects",([
	  __DIR__"npc/nvzi":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

