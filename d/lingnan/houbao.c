
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","���ſ�");
  set ("long", @LONG
�������μұ��󱤵��ſڡ������¾���ס�ں��ˡ�����ƽʱû��
�˰��أ���ʱ���μұ��ĵ��Ӵ�������߹���
LONG);

  set("exits", ([ 

  "north":__DIR__"zhulin",
 "south":__DIR__"xiaojing1",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

