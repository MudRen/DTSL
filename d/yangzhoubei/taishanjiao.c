
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","̩ɽ����");
  set ("long", @LONG
������̩ɽ��ɽ�š�̧ͷ��ȥ��̩ɽ���ʵ�ɽ�������ƶˣ���ʱ��
���˴���������߹��������в�������һ�ɺ��飬Ҫ�ʵ�̩ɽһ����
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu5",
 "south":__DIR__"shanlu4",
 "west":"/d/taishan/daizongfang",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

