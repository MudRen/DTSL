
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������Ҵ�
����������ͨ�򳤰��ǡ�·������ɽͦ�Ρ���ʱ���ԱߵĲݵ���������
ֻ���ӣ�Ȼ�������ŵ��ݴ�������ʧ�ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"guandao1",
 "west":__DIR__"guandao3",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

