
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����·��᫣���ν�ǻ�ɽ���յ�֮һ������ȥ�����Կ�����ɽ
Ρ��ĳ����塣��������ȥ�����Կ�����ɽ��������Ů�塣�ϱ��ǻ�ɽ
����ͤ��
LONG);

  set("exits", ([ 
 "westup":__DIR__"shanlu5",
 "south":__DIR__"xiaqiting",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
