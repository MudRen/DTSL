
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ӵ�");
  set ("long", @LONG
���������ݳǵ��������һ�Ұ��ӵꡣ��������Ĳ��������Ϊ��
�����ټ���ר�������ӵ��Ϸ��С���ɩ�����Ļ�����ò������������
����Ļ����ơ�
LONG);

  set("exits", ([ 
 "west":__DIR__"nanjishi",
        ]));
  set("objects",([
	  __DIR__"npc/zhen":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

