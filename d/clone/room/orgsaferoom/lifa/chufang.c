
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","����");
  set ("long", @LONG
��������߸��ĳ����������������磬һ���������˲�ס��������
ˮ���м���������������æ���������Ա��м�����߸������������̻�
�ʵس��ŷ���
LONG);

  set("exits", ([ 
 "northeast":__DIR__"changlang1",
      ]));
  set("resource/water",1);
  set("objects",([
    "/d/clone/room/orgsaferoom/obj/baozi":2,
    "/d/clone/room/orgsaferoom/obj/xiangsuji":2,
    "/d/clone/room/orgsaferoom/obj/kaoya":2,
    "/d/clone/room/orgsaferoom/obj/yangtui":2,
  ]));
  set("valid_startroom", 1);
  setup();
 
}
