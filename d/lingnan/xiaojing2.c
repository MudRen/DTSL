
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С��������·��ϸ���Сʯ���̳ɡ��������ĵ��š��ϱ�
��һ����԰����ʱ���μұ��ĵ��Ӵ��������������
LONG);

  set("exits", ([ 

  "northwest":__DIR__"xiaojing1",
 "south":__DIR__"huayuan3",
     ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

