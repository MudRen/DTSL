
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��µ�"NOR);
  set ("long", @LONG
�����������ʹ��Ķ�����µ��ˡ�������Ȼ�������������Ҳ��
��˵�����ûʡ����ܰ�����������棬����������һ���������ա�ƽ
ʱ�ʵۺ�����������������ԵñȽ��徻�����˶���������ŷ��ˡ�
LONG);

  set("exits", ([ 
  "north":__DIR__"yushanfang",
  "east":__DIR__"eastdoor",
  "west":__DIR__"zijindian",
         ]));
  set("objects",([
	  __DIR__"npc/duguba":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

