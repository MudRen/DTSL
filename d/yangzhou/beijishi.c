
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵ������֮һ�����С�����Ҳ�����ݵ����ֵĵط�
֮һ���������ġ����յġ���ˣ�ģ���ռһ���������˺ܶ����ˡ�����
������������һ�Ҿ�¥�����㲻ס�ش����ﴫ����ֻ����Ⱥ����һ����
�ã��������������˵��������ڻ�����
LONG);

  set("exits", ([ 
 "northeast":__DIR__"beidajie2",
 "south":__DIR__"beidajie1",
 "east":__DIR__"zuihualou",
        ]));
  set("objects",([
	  "obj/npc/butou":1,
	  __DIR__"npc/old":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

