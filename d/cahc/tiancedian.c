
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ߵ�");
  set ("long", @LONG
�Դ����������˴󹦣�����Ԩ���ͳ�����߸����������͸���
Ϊ��ߵƽ��Ϊ��߸������֮�������ƽ��Ϊ���Σ�������
�䣬�����Ľ��ܼⶥ��ͭ�ƽ𱦶����������ߣ�˫����ȶ���������
��������ʻ���
LONG);

  set("exits", ([ 
 "north":__DIR__"houdian",
 "southdown":__DIR__"tcgc",
 "east": "/d/clone/room/orgsaferoom/lifa/baihutang",
        ]));
set("objects",([
	  "/d/changan/npc/fangxuan-ling":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 "/obj/sboard/lifa_b.c"->foo();
  
}

