
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǽ����ҡ�����ڷ��ż��Ŵ󴲣����ı������롣�����Ƿ���
����������Ϣ�ĵط����Աߵ�ǽ�Ϲ���һ�ڱ�����һ���ֻ���һ������
���������ֱʡ�
LONG);

  set("exits", ([ 
 "southwest":__DIR__"zhulin",
      ]));
  set("valid_startroom", 1);
  set("sleep_room",1);
  setup();
 
}
