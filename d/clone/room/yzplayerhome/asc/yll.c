
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����¥");
  set ("long", @LONG
��������Է�򸾵����ң��м����һ�Ű��񴲣����Ϸ�����
�Ͳʱ����ұ���һ�������¹������ӵ�����Ǻ���Է����ױ
̨(desk)��ǽ�Ϲ��������������е�������ɳ�����޵����ᡱ��
����Է��������������Ǹ��ˡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"xshy",
 "up":__DIR__"lxg",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

