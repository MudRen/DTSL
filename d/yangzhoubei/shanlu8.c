
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·�������������Щ���ˡ���˵����Ҳ�е�����û����
����С��������Զ������ԼԼ���������޺�������������ƺ����ǹٱ�
��ϴ��ƽ����ա�
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu9",
 "southwest":__DIR__"shanlu7",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

