
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ٲ�");
  set ("long", @LONG
������һ���ٲ����ٲ����Ǻܴ󣬵������ƾ��ˣ��������������
�����㲻��Ϊ�������������Ⱦ��
LONG);

  set("exits", ([ 
 "south":__DIR__"shilin",
       ]));
 set("objects",([ "/d/clone/npc/beast/laohu":1,]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

