
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"�㳡"NOR);
  set ("long", @LONG
���������������Զ����ȥ��¥������Ρ��Ĺ�������ʤ������
�ﾭ���йٱ���Ѳ�ߣ��������˸��ڴ�ͣ����
LONG);

  set("exits", ([ 
  "west":__DIR__"guangchang2",
         ]));

  set("objects",([
   __DIR__"npc/gongnv1":1,
   ]));
   
  set("valid_startroom", 1);
  setup();
 
}

