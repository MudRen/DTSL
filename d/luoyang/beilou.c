
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"曼清院北楼"NOR);
  set ("long", @LONG
这里是曼清院的北楼。楼上就是尚秀芳的闺房，一般的寻欢浪子是
没有福气进入的。
LONG);

  set("exits", ([ 
	  "south":__DIR__"huayuan",
	  "up":__DIR__"guifang",
         ]));

  set("valid_startroom", 1);
  setup();
 
}
