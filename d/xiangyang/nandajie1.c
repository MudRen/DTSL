
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�������������ϴ�֡�������һ�ҿ�ջ����С�������ſ��к���
���������ˡ��м�����������������Գ۹�����������˲��Ǻܶࡣ
LONG);

  set("exits", ([ 
 "east":__DIR__"yingbinguan",
 "north":__DIR__"guangchang",
 "south":__DIR__"nandajie2",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

