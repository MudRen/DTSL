
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"��ͤ"NOR);
  set ("long", @LONG
������һ����ͤ��ǰ�ٰ��ɸ��£�����һ���ٲ���к���£�������
�ˣ�����������������Ժ�䴦�ؿ������������׵�ˮ������
LONG);

  set("exits", ([ 

	  "west":__DIR__"zhulin",
	  "southeast":__DIR__"xiaolu5",
  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

