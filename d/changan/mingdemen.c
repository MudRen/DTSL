
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
��������ߴ�Ŷ����������ţ���ʷ�������ܣ��������峯�����
���������ڴ˼��������Ե��ص��˿��ڶ࣬����Ҳ�൱��������������
�����ˣ��ο����ﲻ����ż�����ܿ����������ű��������;���������
ǰվ�ż���ʿ���������ʼ�龭�������ǡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"xiaolu9",
 "north":__DIR__"zqdajie1",
 "southeast":__DIR__"guanlu3",
 "east":__DIR__"xiaolu8",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

