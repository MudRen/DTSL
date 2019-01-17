
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIB"石室"NOR);
  set ("long", @LONG
这里是一个石室，旁边有一张石桌，四周还有几个石凳子。
墙壁上刻着写文字，已经模糊不清了。你可以在这里领悟弈剑派
的内功心法--九玄大法。
LONG);

  set("exits", ([ 
 "out":"/d/yjp/yijiange",
        ]));
  set("no_channel","领悟中还是不要说话了\n");
  set("no_tell","领悟中还是不要说话了\n");
  set("valid_startroom", 1);
  set("force","jiuxuan-dafa");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
