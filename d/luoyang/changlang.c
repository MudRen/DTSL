
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
������һ�����ȡ������Ѿ��ǻʹ����ڲ��ˣ������кܶ��������
���ص�Ѳ�ߡ����ȵ��Ա���һ��ˮ�أ�ˮ�����������Կ������������
�����ζ����м�����Ů���ڳر���ˣ��
LONG);

  set("exits", ([ 
  
  "east":__DIR__"donglang1",
  "west":__DIR__"xilang1",
  "north":__DIR__"jiashan",
  "south":__DIR__"beilang1",
         ]));

  set("objects",([
   __DIR__"npc/gongnv1":1,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

