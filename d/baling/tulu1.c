
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
�����ǰ�����ϵ�һ��С·����Ϊ������Ҫ���������·��״����
�����ã�ֻ����ɳʯ�̳ɣ�·�������ƽ��һ��紵�������������ɳ
����
LONG);

  set("exits", ([ 

  "north":__DIR__"nanmen",
  "south":__DIR__"tulu2",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

