
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����Сͤ"NOR);
  set ("long", @LONG
�����Ǹ�����Сͤ�����������������԰�ľ�ɫ��������԰�ľ�ɫ
���£�������������֮ѧ���������ƺ���һ�����ָ�����������԰�Ƿ�
�������Ľ��أ�ƽʱû����ȥ���
LONG);

  set("exits", ([ 
	  "southwest":__DIR__"hehuachi",
   ]));

  
  set("valid_startroom", 1);
  setup();
 
}

