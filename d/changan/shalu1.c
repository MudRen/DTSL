
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","ɳ·");
  set ("long", @LONG
������һ��ɳ·����紵������Ŀ�ɳ�����߲�Զ���Ǻ��ϵ�����
�ˡ�Զ��һƬ���ߵ���أ����ڳ����ս�ң���������һ�ɲ���֮��
��Ȼ������
LONG);

  set("exits", ([ 
"northwest":__DIR__"dalu2",
"southeast":__DIR__"shalu2",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

