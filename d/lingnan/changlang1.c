
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����ȡ��ȱ��ϵ���˸���ɽˮ��������������һ����
�ʾ�֪���ǳ������ҹ���֮�֡��μұ��������£���ȻҪ����������
�Ĺ����ˡ�
LONG);

  set("exits", ([ 

  "out":__DIR__"door",
  "south":__DIR__"changlang2",
        ]));
  
  set("objects",([
     "/d/job/sjbzahuo/song":1,
     ]));
  
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

