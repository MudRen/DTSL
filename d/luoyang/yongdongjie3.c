
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
������������������֡������߿��Ե������š����Կ����м�����
���������ܵؼ�����������ˡ�
LONG);

  set("exits", ([ 
  
  "northwest":__DIR__"beimen2",
  "south":__DIR__"yongdongjie2",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

