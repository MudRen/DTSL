
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","婴儿室");
	set("long", @LONG
这里是婴儿房，墙壁上贴着卡通图案的壁纸。中间是一张婴
儿床,地下铺着柔软的地毯。小床上各种玩具一应具全。
LONG);
    set("exits", ([
	        "out" : __DIR__"woshi",	       
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
