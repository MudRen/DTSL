
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����Ǻ��ݵĶ���֡������Ǻ��ݵ����ġ��������������������
�����������ϱ���һ��ҩ�꣬�������⻹����һ�󵭵���ҩ�������
��������������˺ܶ࣬���������ߵ�������ȥ��
LONG);

  set("exits", ([ 

  "south":__DIR__"yaodian",
   "east":__DIR__"dongdajie2",
   "west":__DIR__"center",
         ]));
  set("objects",([
	  __DIR__"npc/liumang":1,
	  ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

