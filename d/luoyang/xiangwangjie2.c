
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
������������������֡�������˲��Ǻܶࡣֻ�м���������ʿ��
û����������������Ļʹ����ܶ�ٱ�����������������������
���Ź��������ˡ�
LONG);

  set("exits", ([ 
  
  "west":__DIR__"xiangwangjie1",
  "east":__DIR__"xiangwangjie3",
  "north":__DIR__"door",
  "south":__DIR__"kaiheqiao1"
 
         ]));
  set("objects",([
	  __DIR__"npc/gongzi":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

