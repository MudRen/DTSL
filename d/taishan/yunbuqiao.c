
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ʋ���");
  set ("long", @LONG
������̩ɽ���Ʋ��š��ߵ�������Ѿ��������ƶ��ˡ����ƾ�Ʈ
ɢ�����Χ������������׵���Ԩ��
LONG);

  set("exits", ([ 

   "eastup":__DIR__"wusongting",
   "southdown":__DIR__"zhongtianmen",
          ]));
  set("objects",([
     __DIR__"npc/xiake":1,
     ]));
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

