
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����������������֡������Ѿ��ܷ����ˡ���ս��ʱ�ڣ�������
�����γ��з������������൱�ķ������������������������������֮
���������������
LONG);

  set("exits", ([ 
  
  "east":__DIR__"tianjie2",
  "west":__DIR__"luoshenjie2",
  "north":__DIR__"wangfu",
         ]));
  set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

