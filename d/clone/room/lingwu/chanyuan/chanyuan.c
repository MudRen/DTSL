
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",MAG"苦禅院"NOR);
  set ("long", @LONG
这里是静念禅院的苦禅院。这里可以领悟[lingwu]禅院的内
功心法--闭口禅。几个僧人正做在那里，静默不语。你不禁放轻
了脚步。
LONG);

  set("exits", ([ 
 "out":__DIR__"room",
        ]));
  set("no_channel","领悟中还是不要说话了\n");
  set("no_tell","领悟中还是不要说话了\n");
  set("valid_startroom", 1);
  set("force","bikouchan");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
