
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֡�����ǳ��������㲻��С��������������һ��С
Ϫ��������һ�����¡�
LONG);

  set("exits", ([ 

   "north":__DIR__"xiaoxi2",
   "east":__DIR__"doupo1",
 
          ]));
  set("objects",([
     "/d/dongming/obj/shibei":1,
     ]));
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

