
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @long
�����Ǵ��ϵ����ȣ������Ǹ�˵��Է���
long);

  set("exits", ([ 
 "east":__DIR__"2chuancang6",
 "west":__DIR__"2chuancang5",
 "north":__DIR__"2chuancang8",
 "south":__DIR__"2chuancang2",
 ]));
 
 set("objects",([
	 __DIR__"npc/yahuan1":2,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

