
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǾŽ������š�����ս�ֻ��ң���·Ӣ�۾���ƺ�����������
��ͬ���衣�м��������޾���ɵ�վ��������м�������������
LONG);

  set("exits", ([ 

  "west":__DIR__"nandajie2",
 "enter":"/d/clone/room/cityroom/jiujiang",
        ]));
  set("objects",([
    __DIR__"npc/yayi":2,
 //"/d/job/liyuanjob/jj_junguan":1,
    ]));
  
  set("valid_startroom", 1);
  setup();
 
}

