
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
��������ɽ��ˮ�㣬�̲�����������ɽɫ����ӳ��Ȥ�����ۺ�����
�羵���У������������续���Ρ�����֮�����������Թ�����������
�����ޡ������ġ��㡢�ᡢ������������
LONG);

  set("exits", ([ 
  "south":__DIR__"hupao",
  "west":__DIR__"baiti",
        ]));
 
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

