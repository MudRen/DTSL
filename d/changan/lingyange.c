

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���̸�");
  set ("long", @LONG
����ĳ�����ʤ�����̸󡣴����￴ȥ������ľ�ɫ�����۵ס���
��İ����������ף�����һ������ĸо���
LONG);

  set("exits", ([ 
 "west":__DIR__"dongshidongjie3",
 
        ]));
  set("objects",([
    "/d/quest/yrs/huashi":1,
    ]));
  set("valid_startroom", 1);
  setup();
 
}

