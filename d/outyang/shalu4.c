
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
 "west":__DIR__"shalu3",
 "northeast": "/d/xingyang/xiaolu2",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

