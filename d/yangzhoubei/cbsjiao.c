
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ɽ����");
  set ("long", @LONG
�����ǳ���ɽ���¡�̧ͷ��ȥ������ɽһ���Ǳ�������£�һ����
��ѩ���ǡ�����ԼԼ���Կ�����ɽ���ƺ���һ�����
LONG);

  set("exits", ([ 
 "eastup":"/d/changbaishan/shanlu1",
 "west":__DIR__"shulin2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

