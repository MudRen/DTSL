
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·�����ܹ�ʯ��ᾣ��������ϲ���ǰ��ĵ�·��ս��
ʱ������˵���ֵط��ǵ�����û֮�أ��㲻��С��������
LONG);

  set("exits", ([ 
 "north":__DIR__"shanlu3",
 "southeast":__DIR__"shanlu1",
        ]));
  set("objects",([
     __DIR__"npc/qiangdao":1,
     ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

