
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����������ɵı�����������ɢ�ҵط���һЩ���������������Ա�
���м����������ڴ�ĥ�ű��������Ƕ��Ѿ�������������ˣ�����ֻ��
����������˵�����Ա��м�������������ѡ�ű�����
LONG);
  set("exits",([
	  "south":__DIR__"lianwuchang",
	  ]));
  set("objects",([
	  __DIR__"obj/changjian":2,
	  __DIR__"obj/blade":2,
	  __DIR__"obj/whip":3,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

