
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
����һ�������ɴ���ϵĶ���·�ڣ�·��һ��С��ͨ�򳤰�������
�Ķ��У��������С������ƺ��ǳ����������ֵĵط��ˣ���Ϊ�˻�û����
�������������Ѿ����˹�����
LONG);

  set("exits", ([ 
 "south":__DIR__"wxdajie1",
 "east":__DIR__"dongshixijie4",
 "north":__DIR__"dongshixikou1",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

