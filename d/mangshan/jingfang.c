
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
�������Ͼ��۵ľ������������ż����ƾɵ�������������˳�����
����Ϸ��ż������ҵ��鼮��ǽ�ŷ���һ��ɨ�㣬Ҳ�ǹ�����֩������
LONG);

  set("exits", ([ 

 "east":__DIR__"tingyuan",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

