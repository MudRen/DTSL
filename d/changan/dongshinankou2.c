
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
 "north":__DIR__"dongshidongjie5",
 "west":__DIR__"dongshinankou1",
 "east":__DIR__"xpdajie7",
        ]));
  set("objects",([
   __DIR__"npc/zhuanghan":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

