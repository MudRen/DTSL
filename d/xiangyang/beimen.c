
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ǵı��š��Թ������������Ǿ����صء���������ļ�
��Ҳ�Ƿǳ��ϸ��м����ٱ�ҫ��������վ������Խ��ǵ��˲�ס��
���ȡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"beidajie3",
 "north":__DIR__"beiguanlu1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

