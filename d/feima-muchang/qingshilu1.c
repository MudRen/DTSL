
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
������һ����ʯ·�������˷ǳ��࣬�������£��ǳ����֡��кܶ�
��ǣ��������ȥ��Զ�����Կ��������������м������������ĵ�����
�������������
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"qingshilu2",
	  "south":__DIR__"door",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

