
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"�ٲ�"NOR);
  set ("long", @LONG
�����Ǹ��ٲ�������ĺ������������Ķ�����Щ���顣�ٲ�����
һ����ɫ���ӣ������������������ʯ�ϣ��ֱ�������������顣
LONG);

  set("exits", ([ 

   "west":__DIR__"shanlu4",
          ]));
 set("objects",([
 "/d/yinkui/npc/wanwan":1,
     ]));
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

