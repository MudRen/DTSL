
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"�����"NOR);
  set ("long", @LONG
�����ǻ������������ż������ӣ�û��ʲô�����İ��裬��ȴ��
�����ס�������һ�㱡���ĳ����������Ⱥ���ի�ܾ�û�������ˡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"huayuan",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

