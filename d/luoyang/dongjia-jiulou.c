
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ҿ�¥");
  set ("long", @LONG
���������������Ķ��Ҿ�¥�����������ر�ã�ÿ��������������
�ﲻ�����ܶ�������ʿ������̸�����´��£�����̸�ۺ���赡������
����ȥæ����ͣ��
LONG);

  set("exits", ([ 
  
      "north":__DIR__"luoshuidi3",
      "east":__DIR__"tianjie4",
         ]));
  set("objects",([
	  __DIR__"npc/dong":1,
__DIR__"npc/xiaoer4":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

