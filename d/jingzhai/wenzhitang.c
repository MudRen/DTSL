
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"������"NOR);
  set ("long", @LONG
�����ǴȺ���ի�������á������ǴȺ���ի����ѧϰ�Ļ��ĵط���
������ż������ӣ��������ֽ�źͱʡ�
LONG);

  set("exits", ([ 

  "east":__DIR__"pushantang",
  "west":__DIR__"cangjingfang",
    ]));
  set("objects",([
	  __DIR__"npc/qinwenxin":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

