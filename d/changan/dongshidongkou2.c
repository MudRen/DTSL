
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
 "south":__DIR__"csdajie1",
 "north":__DIR__"dongshidongkou1",
 "west":__DIR__"dongshidongjie4",
        ]));
  set("objects",([
 "/std/orgroom/npc/lixue":1,
 ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

