
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǳ�����������������˵ط��Ÿ��ֱ���������ս�ң����Դ�
����ÿ�����Ӷ����ڱ�ս״̬��
LONG);

  set("exits", ([ 
	  "west":__DIR__"tulu1",
	      ]));
  set("objects",([
	  __DIR__"obj/changjian":2,
	  __DIR__"obj/blade":2,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

