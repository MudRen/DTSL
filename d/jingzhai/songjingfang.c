
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"�о���"NOR);
  set ("long", @LONG
�����ǴȺ���ի���о�����ֻ�������кܶ�Ⱥ���ի�ĵ��ӣ�˫��
��ʮ������𾭡����������ׯ�����£������о������������������
������ࡣ
LONG);

  set("exits", ([ 

  "southeast":__DIR__"zoulang1",
    ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/

  
  set("valid_startroom", 1);
  setup();
 
}

