
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","钟离书院");
  set ("long", @LONG
这里是虚行之先生在长安开设的钟离书院，这个书院开的很有名，
很多长安富户都把孩子送到这里来让虚先生进行教导。书院的讲堂，窗
明几净，一尘不染。一张古意盎然的书案放在房间里，案上摆着几本翻
开了的线装书籍。
LONG);

  set("exits", ([ 
 "west":__DIR__"wxdajie3",
       ]));
  set("objects",([
         __DIR__"npc/xuxing-zhi":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

