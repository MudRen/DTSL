
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ڱ��ſ�");
  set ("long", @LONG
�����Ƿ����������ڱ��ſڡ����Ƿ����������ˣ��ǲ��ܹ���ȥ�ġ�
�кܶ���ǣ��������ȥ��Զ�����Կ��������������м������������ĵ�
�������������������ʱ�з��������������������������
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"qingshilu1",
	  "southeast":__DIR__"caodi1",
         ]));
  set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
"/obj/board/feima_b.c"->foo();
 
}

