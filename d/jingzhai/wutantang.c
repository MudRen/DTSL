
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"��̰��"NOR);
  set ("long", @LONG
�����ǴȺ���ի����̰�á��������õĴȺ���ի�ĵ��ӣ�ÿ������
̰�������֣���Ҫʱ�̽���Ҫ����̰��Գ������ס�
LONG);

  set("exits", ([ 

  "north":__DIR__"qusutang",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

