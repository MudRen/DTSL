
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����췻");
  set ("long", @LONG
�����������췻�������ٽֵĶ���һ������լ���̹ݣ���Ҫ�ṩ��
�������������Ĺ�Ա�����˾�ס��
LONG);

  set("exits", ([ 
      "east":__DIR__"shangguan2",
      "west":__DIR__"guanzhai2",
      "north":__DIR__"qinglongjie",
      "south":__DIR__"qinglongjie2",
  ]));

  set("outdoors","luoyang");

  set("valid_startroom", 1);

  setup();
}

