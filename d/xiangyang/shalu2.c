
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
������һ��ɳʯ·����˵���ﾭ�����ҷ˳��֣��㲻��С��������
ͷ����һЩ��֪����С����������ȥ�����ܴ����ܲ����ʻ��̲�������
�֡�
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shalu1",
  "southeast":__DIR__"shalu3",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

