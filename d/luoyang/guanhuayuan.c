
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��"HIR"��"HIW"԰"NOR);
  set ("long", @LONG
�����������ʹ��Ĺۻ�԰����Ȼ��������԰�󣬵�������Ļ�Ʒ��
���࣬ÿ�춼�л��������ﻤ��������������໨���࿪�ţ�����ͷס�
�����ǻ��Ϻ������Ǿ������ĵط���
LONG);

  set("exits", ([ 
  "south":__DIR__"xidian",
  "north":__DIR__"shijie2",
         ]));
  set("objects",([
   __DIR__"npc/gongnv1":2,
   ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

