
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����Ͽ�");
  set ("long", @LONG
����һ������ƽ����ϵĶ���·�ڣ�·��һ��С��ͨ�򳤰�������
�Ķ��У��������С������ƺ��ǳ����������ֵĵط��ˣ���Ϊ�˻�û����
�������������Ѿ����˹�����
LONG);

  set("exits", ([ 
 "north":__DIR__"dongshixijie5",
 "east":__DIR__"dongshinankou2",
 "west":__DIR__"xpdajie6",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

