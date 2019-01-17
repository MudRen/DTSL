
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是扬州城北的官路。北边就是扬州的北门了。这里的行人很多，
热闹非凡。自古扬州就是江南繁华的中心，看来就是在兵荒马乱的年代，
这里的繁华也不会削减。
LONG);

  set("exits", ([ 
 "north":__DIR__"guanlu2",
 "south":"/d/yangzhou/beimen",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

