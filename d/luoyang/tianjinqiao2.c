
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"�����"NOR);
  set ("long", @long
��������������˾�֮�ף���������ҹ���˾������¹ҿ�֮ʱ����
�����˰ѱ�ͬ�Σ����п�ζ������һ��������
long);

  set("exits", ([ 
  

  "northdown":__DIR__"tianjinqiao1",
  "southdown":__DIR__"tianjinqiao3",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

