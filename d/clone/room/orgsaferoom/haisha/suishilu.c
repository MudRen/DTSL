
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
������һ����ʯ·����·���������Ǻ�ɳ��Ӣ������ϰ���պ���
Ϣ�ĵط���������һ�����䳡��������һ����������ʱ�к�ɳ����Ӵ�
�����߹���
LONG);

  set("exits", ([ 
 "out":__DIR__"longhutang",
 "southwest":__DIR__"lianwuchang",
 "eastdown":__DIR__"chufang",
 "northdown":__DIR__"caodi",
      ]));
  set("valid_startroom", 1);
  set("outdoors","haisha");
  setup();
 
}
