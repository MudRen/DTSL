
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ɴ��");
  set ("long", @LONG
�������ɴ�֣��ϱ���ͨ�����ǡ������ʮ�����֣�������������
��Ϣ��������һ���ܴ������������ǳ���������Ժ�����¡�
LONG);

  set("exits", ([ 
 "north":__DIR__"wxdajie3",
 "south":__DIR__"gmdajie2",
 "east":__DIR__"dongdasi",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

