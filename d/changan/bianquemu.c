
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ȵĹ");
  set ("long", @LONG
��ȵ������ҽ��һ���ĺ���ҽ���������ع���û�뵽���ﾹ������
�����ޡ��ݴ���һ����ҽ��ȵԩ���ڰ�ɱ��ԩ��ȴ������ͬ�У�����
�����������֮�ء�
LONG);

  set("exits", ([ 
"southwest":__DIR__"shanlu1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

