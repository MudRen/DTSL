
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","Сɽ��");
  set ("long", @LONG
������һ����ͻͻ��Сɽ�������˰�ɽ�µļ���С���⣬����û��
�κε�ֲ����Ը���Ҳ�Ϳ�����ʲô���
LONG);

  set("exits", ([ 
 "northdown":__DIR__"shanlu1",
         ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}
