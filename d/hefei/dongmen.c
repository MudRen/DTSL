
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�����ǺϷʵĶ��š���������˲��١������м����ٱ����ڼ����
���İ��ա��Ա߻�վ�ż������٣�ҫ��������վ�������ͣ��ָ�ֻ�
�š�
LONG);

  set("exits", ([ 

  "west":__DIR__"dongdajie3",
"east":"/d/yangzhou/xiaolu3",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

