
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @long
�����Ǵ��ϵ����ȣ������Ǹ�˵��Է���
long);

  set("exits", ([ 
 "east":__DIR__"2chuancang7",
 "west":__DIR__"2chuancang3",
 "north":__DIR__"2chuancang4",
 "south":__DIR__"2chuancang1",
 ]));
 
 set("objects",([
	 __DIR__"npc/yahuan1":2,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

