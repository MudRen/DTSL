
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�μұ�");
  set ("long", @LONG
�������μұ����ſ��ˡ��μұ�������������������һ�����壬��
��Ⱥ�۶��μ��޲���η�мӡ��μұ��������ܹٸ���Լ����������ȫ��
�ľ�����������˵�Ǹ���һ����
LONG);

  set("exits", ([ 

  "enter":__DIR__"changlang1",
  "north":__DIR__"dalu2",
        ]));
  set("objects",([
	  __DIR__"npc/boy":1,
	  __DIR__"npc/girl":1,
	//  "/d/job/banghuijob/songjia":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
"/obj/board/songjia_b.c"->foo();
 
}

 int valid_leave(object ob,string dir)
{
if(!userp(ob)) return 0;
 return ::valid_leave(ob,dir);
}
