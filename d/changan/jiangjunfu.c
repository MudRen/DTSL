
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����ǳ�����һ�������������ﰲ�����ˣ���ͨ�����ߵ������
�������˽Ų�������ס������߸���������ͺ��Ů�򸾣����˲���
��Ȼ�𾴡�
LONG);

  set("exits", ([ 
 "west":__DIR__"ahdajie3",
        ]));
  set("objects",([
      "/d/job/questjob/npc/hongfu":1,
      ]));
  set("valid_startroom", 1);
  setup();
 
}

