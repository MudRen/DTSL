
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���б���");
   set ("long", @LONG
����һ���ڹ�������ϵĶ���·�ڣ�·��һ��С��ͨ�򳤰�������
�Ķ��У��������С������ƺ��ǳ����������ֵĵط��ˣ���Ϊ�˻�û����
�������������Ѿ����˹�����
LONG);

  set("exits", ([ 
 "south":__DIR__"dongshixijie1",
 "east":__DIR__"dongshibeikou1",
 "west":__DIR__"gmdajie2",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

