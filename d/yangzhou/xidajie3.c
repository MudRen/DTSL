
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������ݳǵ�����֡�����������ݵ����������ˡ�����������
�����ֵĵط������������ݵ����ּ���֮һ�����С�������Ϳ�������
�ּۻ��۵�������������һ�ҿ�ջ�����������ⲻ����С���������
�к������������ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"xihudi2",
 "west":__DIR__"xidajie2",
 "north":__DIR__"kezhan",
 "south":__DIR__"xijishi",
        ]));
  set("objects",([
	  __DIR__"npc/haoke":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

