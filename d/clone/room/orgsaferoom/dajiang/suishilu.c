
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
������һ����ʯ·����·���������Ǵ���Ӣ������ϰ���պ���
Ϣ�ĵط���������һ�����䳡��������һ����������ʱ�д������Ӵ�
�����߹���
LONG);

  set("exits", ([ 
 "out":__DIR__"juyitang",
 "westdown":__DIR__"lianwuchang",
 "east":__DIR__"chufang",
 "northdown":__DIR__"caodi",
      ]));
  set("valid_startroom", 1);
  set("outdoors","dajianglian");
  setup();
 
}
