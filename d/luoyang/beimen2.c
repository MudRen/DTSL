
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������"NOR);
  set ("long", @LONG
�����������������ţ�������Ҳ������ǡ���ǽ��վ�ż���ʿ����
�����ؿ��Ž��������ˡ�
LONG);

  set("exits", ([ 

  "southeast":__DIR__"yongdongjie3",
  "west":__DIR__"beimen",
 
  ]));
  set("objects",([
	  __DIR__"npc/bing":1,
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

