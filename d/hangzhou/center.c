
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ĺ㳡");
  set ("long", @LONG
�����Ǻ��ݵ������ˡ������Ǻ��������ֵĵط��ˣ��㼯�������
�����οͣ������������ò����֡�����οͶ��������ߵ�������ȥ����
ͷ���кܶ�������С����㲻��Ϊ�����������������Ⱦ�ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie1",
  "north":__DIR__"beidajie2",
  "west":__DIR__"xidajie1",
  "east":__DIR__"dongdajie1",
         ]));
  set("objects",([
	  __DIR__"npc/youke1":1,
	  __DIR__"npc/guniang":1,
	  ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

