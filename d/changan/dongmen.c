
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���ǳ����ǵĶ���--�����ţ��������Ϸ����š������š����������
�֣���ǽ�����ż��Źٸ���ʾ���ٱ��Ǿ����ע���Ź������ˣ������
С��Ϊ�һ����ֱ����ʯ���������������졣�����ǽ��⣬��Լ
�ɼ�һƬһ���޼ʵ����ּ�ɽ��������Ī�⡣
LONG);

  set("exits", ([ 
"west":__DIR__"gmdajie1",
"east":__DIR__"guanlu1",
"north":__DIR__"xiaolu0",
"south":__DIR__"xiaolu7",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

