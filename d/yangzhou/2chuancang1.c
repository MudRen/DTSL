
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @long
�����Ǵ��ϵĲ��������������������뻨���������һ��������
����һ��Ʒ����ζ���ȡ�
long);

  set("exits", ([ 

 "north":__DIR__"2chuancang2",
 "down":__DIR__"chuancang",
 ]));
 
 set("objects",([
	 __DIR__"npc/yahuan1":2,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

