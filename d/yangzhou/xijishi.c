
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݵ������֮һ�����С�����Ҳ�����������ֵĵط�֮
һ��ÿ���кܶ��������������⣬������������۵������������ƺ���
����������ʱ����ս�������Ŀ��ա�
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie3",
 "south":__DIR__"yanju",
        ]));
  set("objects",([
   __DIR__"npc/xiaofan":1,
   __DIR__"npc/jumin":1,
   ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

