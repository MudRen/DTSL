
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·��Զ����һ��ɽ��������������ĳ���ɽ��������Щ
�䣬������Χ�ľ����㲻������һ�������ĸо���
LONG);

  set("exits", ([ 
 "southeast":__DIR__"shanlu10",
 "west":__DIR__"shanlu8",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

