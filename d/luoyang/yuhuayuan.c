
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��"HIR"��"HIY"԰"NOR);
  set ("long", @LONG
�����������ʹ�������԰������Ļ�Ʒ�ַ��࣬ÿ�춼�л�������
�ﻤ��������������໨���࿪�ţ�����ͷס������ǻ��Ϻ������Ǿ�
�����ĵط���
LONG);

  set("exits", ([ 
  
  "east":__DIR__"xilang2",
  "north":__DIR__"qingong",

         ]));
  set("objects",([
   __DIR__"npc/gongnv1":2,
   ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

