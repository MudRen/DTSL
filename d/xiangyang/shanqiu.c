
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
��������ɽ��΢�紵����һ���ɳ΢΢��������羰������ɽ
ˮ�续���������¡���ʱ����������ͷ�Ϸɹ���
LONG);

  set("exits", ([ 
 "southeast":__DIR__"shashilu1",
       ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

