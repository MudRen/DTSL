
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"����ɽ��"NOR);
  set ("long", @LONG
������ǡ������ɡ���ɽ���ˡ���Ϊ������һ��а�̣�����Ŀ���
��ν�ϸ�����ص����Σ�ƽ���˵��Ǻ����ҵ��ġ��������������
���ɵ��ڲ��ˡ���˵�����ɵ��书��а�����ƣ�ѧ��֮��ÿ�������׺�
���̣�����ƽʱû���˸�������ġ�
LONG);

  set("exits",([
      "north":__DIR__"xiaoshilu1",
      "eastdown":"/d/chengdu/shijie6",
	  "east":__DIR__"caocong1",
	  ]));
  set("objects",([
	  __DIR__"npc/dizi2":1,
	  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
   "/obj/board/party_yg_b.c"->foo();
 
}

