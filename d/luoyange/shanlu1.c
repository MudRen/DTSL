
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ͨ������ɽ�ϵ�С·��ңң��ȥ�����ߵ�ɽ��߸�������
�ƺ��кܶ�¥���������С���ʱ�����������������Գ۹���
LONG);

  set("exits", ([ 
  "southeast":__DIR__"xiaolu3",
  "northwest":__DIR__"shanlu2",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

