
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ʳ�����");
  set ("long", @LONG
�����ǻʳǵ����š������߿��Ե������š����Կ����м����ٱ���
�����ܵؼ�����������ˡ�
LONG);

  set("exits", ([ 
  
  "north":__DIR__"yongdongjie2",
  "south":__DIR__"jiashan",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

