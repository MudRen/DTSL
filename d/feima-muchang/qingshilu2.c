
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
������һ����ʯ·�������˷ǳ��࣬�������£��ǳ����֡��кܶ�
��ǣ��������ȥ��Զ�����Կ��������������м������������ĵ�����
�������������������һ��԰�֡�
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"yuanlin",
	  "south":__DIR__"qingshilu1",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

