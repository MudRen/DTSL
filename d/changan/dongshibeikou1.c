
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
 "south":__DIR__"dongshidongjie1",
 "east":__DIR__"gmdajie1",
 "west":__DIR__"dongshibeikou2",
        ]));
  set("objects",([
   __DIR__"npc/youke":1,
   __DIR__"npc/xiaofan":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

