
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������������֡������������Ĺٸ����������ڸ�·Ӣ�۸��Գ�
�������Թٸ�Ҳ��������ʵ����ֻ�м����ٱ���ɢ��վ�����һ����
����˯�����ӡ����߾��������ǵ������ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"guangchang",
 "west":__DIR__"xidajie2",
 "enter":"/d/clone/room/cityroom/xiangyang",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

