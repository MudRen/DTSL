
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ǵ����ҡ���������࣬�����Ǹ����˴�ɨ�������ϵı�
������������롣�����Ϸ���һ��д�õ��鷨���ּ��������Ծ�������
���罣�档ǽ���Ϲ���һ�ѳ�����
LONG);

  set("exits", ([ 

  "west":__DIR__"liangting2",
      ]));
  set("objects",([
	  __DIR__"npc/songzhi":1,
	  ]));

  set("valid_startroom", 1);
  
  setup();
 
}

