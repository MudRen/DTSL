
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"�����"NOR);
  set ("long", @LONG
�����ǴȺ���ի�ĺ����ϱ��ǴȺ���ի�������ˡ���������壬
��������壬��������㲻���������徻���ƺ����������еķ��ա�
LONG);

  set("exits", ([ 

  "north":__DIR__"suishilu2",
  "south":__DIR__"zhengdian",
      ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

