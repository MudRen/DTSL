
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·����ɳ�ܴ��㲻�ɱս���˫�ۡ��������߾ͳ���
���ϵľ��ض����밲�յľ����ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"shalu4",
 "south":__DIR__"shulin4",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

