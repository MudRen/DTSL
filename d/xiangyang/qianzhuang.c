
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Ǯׯ");
  set ("long", @LONG
����������һ��������Ǯׯ����������ս�ң���������Ⲣ���Ǻ�
�á��ſڽ������Ʒ��������˺ܶ�ǿ�����ϰ����������������Ŀ����
���������ſ�������ϴ��
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie3",
        ]));
  set("objects",([
	  __DIR__"npc/shen":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

