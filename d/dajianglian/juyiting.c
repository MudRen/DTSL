
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","����ͤ");
  set ("long", @LONG
�����Ǵ����ľ���ͤ������������������н����ʽ�������
�Ͻ�ˮ��������в��ɵ�����һ�ɺ�׳֮�������ﻹ��һ������(lian)��
LONG);

  set("exits", ([ 
	  "south":__DIR__"tulu2",
	      ]));
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("item_desc",([
      "lian":HIG"����ͤ�����屡����\n�����̽���Х����\n"NOR,
       ]));
  set("valid_startroom", 1);
  setup();
  "/obj/sboard/dajiang_b.c"->foo();
}

