
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
����������������֡�������������������ˡ�����Ҳ�кܶ�С��
���ڽ�������������˲��Ǻֻܶ࣬���ϱ߹ٱ������ܵļ����������
�ˡ�
LONG);

  set("exits", ([ 
  "north":__DIR__"nanjie3",
  "south":__DIR__"nanmen",
  "east":__DIR__"pingfu_laodian",
  "west":__DIR__"ygrestroom1",
         ]));
  set("objects",([
     "/d/yinkui/npc/danmei":1,
     ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}


