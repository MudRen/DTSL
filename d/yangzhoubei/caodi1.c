
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
����Ƭ�ݵء��򱱱���ȥ�����Կ���һ�������ݵ���������·��
ʮ�������
LONG);

  set("exits", ([ 
 "north":__DIR__"gaoyouhu",
 "southeast":__DIR__"xiaolu2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

