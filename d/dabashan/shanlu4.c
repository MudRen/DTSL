
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��������һ��ɽ�������ܹ�ʯ��ᾣ����ο�������
����Ҫ��������һ��ɽ�£�����������ɽ��·��
LONG);

  set("exits", ([ 

   "east":__DIR__"shanji1",
   "westdown":__DIR__"shanpo",
         ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

