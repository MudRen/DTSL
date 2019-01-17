
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangnan"
#define TO __DIR__"jiangbei"
#include "/std/shiproom.c";
void create ()
{
  set ("short","长江南岸");
  set ("long", @LONG
这里是长江的南岸。过了长江，就到了湖北的境地了。眼前江水滚
滚，只有一叶扁舟摆渡来往的行人。
LONG);

  set("exits", ([ 

  "south":__DIR__"tulu5",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

