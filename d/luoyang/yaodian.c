
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ҩ��");
  set ("long", @LONG
������һ��ҩ�ꡣ����ս�����꣬�������������ܺá������ҩ
��������ȫ�������������кܸߵ�������
LONG);

  set("exits", ([ 
 "west":__DIR__"changxiajie4",
        ]));
 set("objects",([
	 __DIR__"npc/wangdaifu":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

