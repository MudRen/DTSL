
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ˮ��");
  set ("long", @long
��ˮ�̱���ֲ���������̳��񣬷羰���ˡ�
long);

  set("exits", ([ 
  
  "north":__DIR__"tianjinqiao3",
  "west":__DIR__"luoshuidi1",
  "east":__DIR__"luoshuidi3",
  "south":__DIR__"baihujie1",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

