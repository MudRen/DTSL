
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�������μұ��ı����ҡ�����ɢ�ҵط���һЩ�������Ա߻��м���
�����������������ش�ĥ�ű������м����μұ��ĵ��������Ա���ѡ��
�Լ����ֵı�����
LONG);

  set("exits", ([ 

   "west":__DIR__"wuchang",
     ]));
  set("objects",([
	  __DIR__"obj/blade":3,
	  __DIR__"obj/guai":3,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

