
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������Ƭ�ݵء�����û��ʲôװ�Σ����Ե���Щׯ�ϵ����գ��ƺ�
���ϱߵ�С�ݴ�����ɱ����
LONG);

  set("exits", ([ 

   "northwest":__DIR__"yuedongmen",
   "southeast":__DIR__"modaotang",
        ]));
  set("objects",([
	  "/d/clone/npc/ouyangqian":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

