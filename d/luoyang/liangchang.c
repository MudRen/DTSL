
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @long
��Ȼ������Χ�Ѿ�����������֮��������������������Ȼ�ڳ��ڽ�
����һ������֮����ƽʱ���ر��������Է����⡣
long);

  set("exits", ([ 
      "west":__DIR__"nanjie2",
      "east":__DIR__"liangchang2",
  ]));
  set("objects",([
	  __DIR__"npc/wujiang2":2,
  ]));
  set("valid_startroom", 1);
  setup();
 
}

