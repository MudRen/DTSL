
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @long
�����Ǵ��ϵ����ȣ������Ǹ�˵��Է���
long);

  set("exits", ([ 
 "east":__DIR__"chuancang3",
 "west":__DIR__"chuancang4",
 "north":__DIR__"chuancang5",
 "south":__DIR__"chuancang1",
 ]));
 
 set("objects",([
	 __DIR__"npc/yahuan1":2,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

