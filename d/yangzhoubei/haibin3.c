
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǻ������ϱ���ãã�Ĵ󺣡������Ѿ����������ˣ�������Щ
���ˣ������������ɺ��˹�����
LONG);

  set("exits", ([ 
 "east":__DIR__"haibin4",
 "west":__DIR__"haibin2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

