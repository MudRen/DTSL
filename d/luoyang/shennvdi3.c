
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","神女堤");
  set ("long", @long
走到这里，景色又是一变，洛水在这里转了个弯，变的宁静优美就
好象一个美丽的女神。这也是女神堤这个名字的由来。
long);

  set("exits", ([ 
  
  	"west":__DIR__"shennvdi2",
  	"east":__DIR__"dongbianmen2",
  
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

