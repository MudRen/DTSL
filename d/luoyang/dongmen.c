
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������"NOR);
  set ("long", @LONG
�����������Ķ��š���Ϊ�����ĳ��У�ƽʱ�кܶ����������ǡ���
�����������ţ��м���ȫ����װ�Ĺٱ���վ��������ſڵĹٱ�����
�������ܵؼ�����������ˡ�
LONG);

  set("exits", ([ 
  

  "west":__DIR__"xiangwangjie3",
  "north":__DIR__"dongbianmen1",
  "southup":__DIR__"dongchenglou",
  "east":"/d/luoyange/guanlu1",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

