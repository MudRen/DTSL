
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬï�ܵ����֡������Ѿ������ֵı�Ե�������͵���к��
�����ε�����Щ������˫�ۡ���������ס��ͷ�����ֶ�����һ��ɽ�壬
�ϱ߻���һ��ɽ·��
LONG);

  set("exits", ([ 

   "east":__DIR__"shanfeng",
   "west":__DIR__"shulin2",
   "south":__DIR__"shanlu3",
   "north":"/d/clone/room/iron/room1",
  
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

