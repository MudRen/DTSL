
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǻ�ɳ��ĳ����������������磬һ���������˲�ס��������
ˮ���м���������������æ���������Ա��м�����ɳ������������̻�
�ʵس��ŷ���
LONG);

  set("exits", ([ 
 "westup":__DIR__"suishilu",
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
