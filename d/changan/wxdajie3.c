
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ɴ��");
  set ("long", @LONG
�������ɴ�֣��ϱ���ͨ�����ǡ������ʮ�����֣�������������
��Ϣ�������ƺ���һ����Ժ����Ϊ�����ŵĶ����������ﴫ����
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie7",
 "south":__DIR__"wxdajie2",
 "east":__DIR__"zlshuyuan",
        ]));
  set("objects",([
   __DIR__"npc/baixing":1,
   __DIR__"npc/youke":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

