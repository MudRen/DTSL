
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ܼǳ��ׯ");
  set ("long", @LONG
������������һ�����ׯ������������·����۴󷽣�����Թ���
�ﲻ���ص�������ѡ�ʵ������
LONG);

  set("exits", ([ 
 "west":__DIR__"changxiajie1",
        ]));
 set("objects",([
	 __DIR__"npc/ma":1,
	 __DIR__"npc/huoji":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

