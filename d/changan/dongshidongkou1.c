
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
����һ���ڳ�������ϵĶ���·�ڣ�·��һ��С��ͨ�򳤰�������
�Ķ��У��������С������ƺ��ǳ����������ֵĵط��ˣ���Ϊ�˻�û����
�������������Ѿ����˹�����
LONG);

  set("exits", ([ 
 "south":__DIR__"dongshidongkou2",
"north":__DIR__"gmdajie1",
 "west":__DIR__"dongshidongjie2",
        ]));
  set("objects",([
   __DIR__"npc/xiaojie":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

