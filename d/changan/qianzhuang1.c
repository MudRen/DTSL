
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","荣富钱庄");
  set ("long", @LONG
这家钱庄据说是平窑富商欧阳福荣在长安开的分号，欧阳福荣靠典
当起家，富甲一方，如今，又做起了钱庄的生意，这里发行的银票是通
行全国的。
LONG);

  set("exits", ([ 
 "west":__DIR__"xishixijie5",
        ]));
  set("objects",([
	  __DIR__"npc/qian":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

