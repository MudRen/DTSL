
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���̸�");
  set ("long", @LONG
����֩�������ֵ�С������ǰ��Ȼ���ʣ�������֮������ֲ���ֻ�
�ܲ�ľ�����̵ĵ�ˮӳ���£����̸�������䣬̨��ͤ�������ܵĻ�
���ڻ�Ϊһ������ס������Ԩ�ĳ����Ž�楡� 
LONG);

  set("exits", ([ 
 "south":__DIR__"dongyuchi",
        ]));
  set("objects",([
           __DIR__"npc/zhangjieyu":1,
        ]));
  set("valid_startroom", 1);
  setup();
 
}

