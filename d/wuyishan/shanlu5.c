
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·������û��ʲô������������������������ϱ�
��һƬ�����֣�����ïʢ��������ȥ�����׶༪�٣����ǲ���ȥΪ�á�
LONG);

  set("exits", ([ 

   "northeast":__DIR__"shanlu3",
    "southwest":__DIR__"jingjilin",
           ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object ob,string dir)
{
  if(dir=="southwest"&&!userp(ob))
  	return 0;
  
  return ::valid_leave(ob,dir);

}
