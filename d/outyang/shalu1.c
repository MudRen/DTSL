
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
 "northwest":__DIR__"guanlu2",
 "southeast":__DIR__"shalu2",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

