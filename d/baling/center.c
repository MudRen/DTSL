
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����㳡");
  set ("long", @LONG
�����ǰ�籵������ˣ�����ȽϷ���������Ҳ�ܶࡣ���������ܶ�
���ˣ������������ò����֡��м��������ĵ���������ȥ��������
�ơ����յ������Ⱥ���ò����֡������ٱ��������￴���������
LONG);

  set("exits", ([ 

  "southwest":__DIR__"xijie1",
  "southeast":__DIR__"dongjie1",
  "north":__DIR__"qingshilu1",
       ]));
 set("objects",([
	 __DIR__"npc/bing2":1,
	 __DIR__"npc/bldizi":1,
	 ]));
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

