
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�������������ϴ�֡�������һ�Ҿ�¥�����治ʱ�����Ⱦƽ����
�����������˶�������м�������������ҡҡ�λ��߹������ﲻ
֪�����ֹ���ʲô�������������ĳ����У��м����ٱ�����������ȥ��
LONG);

  set("exits", ([ 
 "west":__DIR__"chemahang",
 "north":__DIR__"nandajie1",
 "south":__DIR__"nandajie3",
 "east":__DIR__"jiulou",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

