
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����·��᫣���ν�ǻ�ɽ���յ�֮һ������ȥ�����Կ�����ɽ
Ρ��ĳ����塣����ȥ�����Կ�����ɽ��������Ů�塣�ϱ��ǻ�ɽ��
ӭ������
LONG);

  set("exits", ([ 
 "west":__DIR__"shanlu4",
 "southeast":__DIR__"yingyangdong",
 "eastdown":__DIR__"shanlu7",
 "northup":__DIR__"shanlu6",
 "eastup":__DIR__"chaoyangfeng",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
