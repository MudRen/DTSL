
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ж���");
  set ("long", @LONG
�����Ƕ����ĺ������в�������¥�󣬶�����ɵ��ھ��Ǿ�
ס�ĵط������������ʹ���������գ�������װ��Ů��̫��������ʰ��
�䡣
LONG);

  set("exits", ([ 
 "northdown":__DIR__"qingshilu3",
 "south":__DIR__"guangtiandian",
 "westdown":__DIR__"tongxunmen",
    ]));
    set("objects",([
         __DIR__"npc/shinv":1,
    ]));
  
  
  set("valid_startroom", 1);
  setup();
 
 
}

