
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
���������������������У������У������������еĶ��֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ�����ε꣬��
����һ��ҩ�ꡣ
LONG);

  set("exits", ([ 
  "north":__DIR__"xishibeikou2",
  "south":__DIR__"xishidongjie2",
  "west":__DIR__"baorentang",
  "east":__DIR__"shoushidian",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

