
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
�������λ����������ϵ��������������У������еĶ��ڣ�ʮ��
·�������������ߵ����ַǷ������С�������һ��Ư����԰�֣�������
���Ŵ�ס�����档
LONG);

  set("exits", ([ 
 "north":__DIR__"xishidongkou1",
 "south":__DIR__"yadajie1",
 "westup":__DIR__"ymqiao",
 "east":__DIR__"xijiyuan",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

