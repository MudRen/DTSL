
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǽ����ҡ�����ڷ��ż��Ŵ󴲣����ı������롣�����Ǻ�ɳ
�������Ϣ�ĵط����Աߵ�ǽ�Ϲ���һ�ڱ�����һ���ֻ���һ�����ǳ�
�������ֱʡ�
LONG);

  set("exits", ([ 
 "southdown":__DIR__"caodi",
      ]));
  set("valid_startroom", 1);
  set("sleep_room",1);
  setup();
 
}
