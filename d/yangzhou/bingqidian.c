
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������һ�ұ����꣬�������ı�����̣���������������������
������������ܵ�ǽ�ڣ�����Ѭ�������ѵ����ϵ��·������¿�ȥ��ֻ
���������ų������ֵ�����¯�����ҫ���������⡣ֻ��������������
���ô��ֻ����һ�ѷ����ı�����¯�ˡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"dongdajie1",
       ]));
  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

