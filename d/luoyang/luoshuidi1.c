
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ˮ��");
  set ("long", @long
��ˮ�̱���ֲ���������̳��񣬷羰���ˡ�
long);

  set("exits", ([ 
  

  "west":__DIR__"xibianmen2",
  "east":__DIR__"luoshuidi2",
  "south":__DIR__"pigedian",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

