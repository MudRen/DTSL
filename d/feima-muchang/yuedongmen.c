
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"�¶���"NOR);
  set ("long", @LONG
������һ���¶��š������˵�Ƿ��������Ľ��أ�û�г���������
��û���˸�ȥ����ġ����ﾲ���ĵģ�û��˿����������
LONG);

  set("exits", ([ 
	  "east":__DIR__"huayuan2",
	  "west":__DIR__"yuanlin",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

