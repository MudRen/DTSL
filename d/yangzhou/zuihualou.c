
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��¥");
  set ("long", @LONG
���������ݳǵĵ������ľ�¥--��¥���������ݵĽ������ͣ���
Ҫ��������ʾһ���Լ�������ÿ�춼���������֡���С��������ȥ��æ
����ͣ����������Ľ������������������̸���ź���赵����飬�Ա�
���м����ٱ��ڴ��������ǡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"beijishi",
        ]));
  set("objects",([
	  __DIR__"npc/zhao":1,
	  __DIR__"npc/xiaoer":1,
	 
	  ]));
  set("valid_startroom", 1);
  set("no_fight",1);
  setup();
  "/obj/board/pal_b.c"->foo();
 
}

