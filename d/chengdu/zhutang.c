
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"����"NOR);
  set ("long", @LONG
�����Ƕ��𱤵����á���ǰ������ʯʨ�ӣ���������ׯ�ϵ����ա�
���������һ�Ѵ����ӣ�����������һ��С���ӡ�����ׯ�����£�����
������Ҳ���ҳ�һ����
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"qiao",
	  "southeast":__DIR__"ceyuan",
	  "east":__DIR__"donglang1",
	  "west":__DIR__"xilang1",
         ]));
  set("valid_startroom", 1);
  setup();
  "/obj/sboard/duzun_b.c"->foo();
}
