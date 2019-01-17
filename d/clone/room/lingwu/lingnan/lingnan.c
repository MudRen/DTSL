
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIG"天罡堂"NOR);
  set ("long", @LONG
这里是岭南宋家堡的天罡堂。堂前挂着一把大刀，刀锋锐利，
闪闪发光，寒气逼人。在这里你可以领悟「lingwu」宋家堡的内
功心法--天罡三绝。
LONG);

  set("exits", ([ 
 "out":__DIR__"baihutang",
        ]));
  set("no_channel","领悟中还是不要说话了\n");
  set("no_tell","领悟中还是不要说话了\n");
  set("valid_startroom", 1);
  set("force","tiangang-sanjue");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
