
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�����Ǹ����ҡ�������Ժ�������Ϲ�����Ϣ�ĵط��������кܶ���
Ů���ź��Ϲ��������ﲼ�õĸ����ûʡ�
LONG);

  set("exits", ([ 
	  "down":__DIR__"nanlou",
  ]));
  set("objects",([
	  __DIR__"npc/shangguan-long":1,
  ]));

  set("valid_startroom", 1);
  setup();
 
}
