
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǻ������ϱ���ãã�Ĵ󺣡���Դ󺣣����ж�ʱ���������
��࣬�����ڶ�Ŀ����ڴ���ǰ��������ʧ��һ�ɶ�����
LONG);

  set("exits", ([ 
 "northeast":__DIR__"haibin5",
 "west":__DIR__"haibin3",
        ]));
  set("objects",([
    __DIR__"npc/youke":2,
    ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

