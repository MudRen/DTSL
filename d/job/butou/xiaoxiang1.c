
#include <ansi.h>
inherit ROOM;
#include <job_money.h>

void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С�ƽʱ�кܶ��Ʀ��å�ۼ������
LONG);

  set("exits", ([ 

  "north":"/d/baling/dongjie1",
     ]));
 set("objects",([
	 "/d/baling/npc/liumang":1,
	 "/d/baling/npc/liumang2":1,
	 ]));
set("outdoors","baling");
  set("valid_startroom", 1);
  setup();
 
}

