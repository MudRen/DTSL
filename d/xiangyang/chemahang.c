
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������������ǵĳ����У��ܹ����������ϵĳ���Ӧ���м���
�ٱ����޾���ɵ�վ������������Ҳ��ȱ��ι����ͬ���������ķ�
��������ȣ���������֮���ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"nandajie2",
       ]));
  set("objects",([
	  __DIR__"npc/lizongbing":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

