
#include <ansi.h>
#include <job_money.h>
inherit ROOM;

int do_claw(string arg);
void create ()
{
  set ("short","山崖");
  set ("long", @LONG
这里是一个山崖。这里有很多野生的草药，许多医生专门到这里采
草药。
LONG);

  set("exits", ([ 
 "south":__DIR__"xuanya",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

