
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ٸ�Ǯׯ");
  set ("long", @LONG
���Ǯׯ��˵��ƽҤ����ŷ�������ڳ������ķֺţ�ŷ�����ٿ���
����ң�����һ���������������Ǯׯ�����⣬���﷢�е���Ʊ��ͨ
��ȫ���ġ�
LONG);

  set("exits", ([ 
 "west":__DIR__"xishixijie5",
        ]));
  set("objects",([
	  __DIR__"npc/qian":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

