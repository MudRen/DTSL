
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�����߾����Ĵ��Ķ����ˡ���������˽�������������
��ʱ�м������ɿ��ܹ���
LONG);

  set("exits", ([ 
 "east":__DIR__"tulu3",
 "westup":"/d/chengdu/zhandao3",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

