
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ɴ��");
  set ("long", @LONG
�������ɴ�֣��ϱ���ͨ�����ǡ������ʮ�����֣�������������
��Ϣ��������һƬ������סլ����
LONG);

  set("exits", ([ 
 "north":__DIR__"dongshixikou2",
 "south":__DIR__"xpdajie6",
 "west":__DIR__"xuanpingfang",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

