
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֡��������ľïʢ����ס�����⣬���Կ���������
��Щ������������˼ʺ�����ֻ�м�ֻҰ�þ�������������ܹ���
LONG);

  set("exits", ([ 
 "west":__DIR__"shanlu6",
       ]));
 set("objects",([ "/d/clone/npc/beast/xiong":1,]));
   set("valid_startroom", 1);
   set("no_select",1);
   set("outdoors","huashan");
  setup();
 
}
