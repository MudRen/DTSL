
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
�������λ����������ϵ��������������У������еĶ��ڣ�·��
�����������ߵ����ַǷ������С�
LONG);

  set("exits", ([ 
 "north":__DIR__"gmdajie6",
 "south":__DIR__"xishidongkou2",
 "westup":__DIR__"fyqiao",
         ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

