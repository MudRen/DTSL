
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǻ������ϱ���ãã�Ĵ󺣡�����ͣ�ż����洬��Զ����һ��
С��壬��������Щ�����������ܿ��Ҫ����˼��ˡ�
LONG);

  set("exits", ([ 
 "southeast":__DIR__"haibin7",
 "west":__DIR__"haibin5",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

