
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������Ҵ�
����������ͨ�򳤰��ǣ�����������ˮ��·������ɽͦ�Ρ���ʱ���Ա�
�Ĳݵ���������ֻ���ӣ�Ȼ�������ŵ��ݴ�������ʧ�ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"guandao4",
 "west":"/d/tuyuhun/tianshui",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

