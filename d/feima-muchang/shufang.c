
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�鷿");
  set ("long", @LONG
���ڲ���һʽ��ľ�Ҿߡ����Ϸ����ķ��ı������ڵĹ�����ǹ���
���裬�ڹ���ӳ���£�ǽ��һ�ڻ�����һ�����������顰����֮������
��Ȥ����������������¡���
LONG);

  set("exits", ([ 
	  "west":__DIR__"feiniao_yuan",
    ]));

  set("objects",([
	  __DIR__"npc/shangxiu-xun":1,
	  ]));
set("no_clean_up",1);
  set("valid_startroom", 1);
  setup();
 
}

