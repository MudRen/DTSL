
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"����"NOR);
  set ("long", @LONG
�����ǴȺ���ի�����������һ�������Ա߻��м���С����
������������̬���ꡣ����������һ�����ң�����д�š��������Ƶ��
�м��������������о����
LONG);

  set("exits", ([ 

  "north":__DIR__"houqingdian",
  "south":__DIR__"huayuan",
  "east":__DIR__"wuwangdian",
  "west":__DIR__"jingxindian",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

