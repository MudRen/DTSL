
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ƕ��𱤵ı����ҡ�������źܶ�������絶�����ȡ��м���
�������������ĥ�ű������������𱤵��������Ա���ѡ���Լ����ֵ�
������
LONG);

  set("exits", ([ 
	  "west":__DIR__"wuchang",
        ]));
  set("objects",([
	  __DIR__"obj/changjian":2,
	  __DIR__"obj/blade":2,
	  __DIR__"obj/chutou":2,
	  ]));
set("valid_startroom", 1);
  setup();
 
}
