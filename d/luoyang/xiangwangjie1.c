
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�������");
  set ("long", @LONG
������������������֡����߾�������������ˡ���������������
�ֵĵط��ˣ��������������������ֵ��������м����ٱ����������
�Ҵ��߹�����ʱ���������������ˡ�
LONG);

  set("exits", ([ 
  
  "west":__DIR__"tianjie2",
  "east":__DIR__"xiangwangjie2",
  "north":__DIR__"qingshilu1",
 
         ]));
   set("objects",([
   "/d/clone/npc/ouyang-xiyi":1,
   ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

