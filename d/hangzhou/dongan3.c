
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����������Ķ���������ͣ�ż���С�����кܶ��ο͵Ǵ�ȥ������
���ķ�⡣����̲����ԣ���ɫ�������㲻�������������ס�ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"dongan1",
 "southwest":__DIR__"nanan1",
        ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

