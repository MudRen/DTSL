
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
��䷹����Ȼ���󣬵������⵹�Ƿǳ��ĺã�����ר���ṩ���ص�
���ַ�ζС�ԣ�������һ�ſ���������������С����������һ����ë��
Цӯӯ���������˹�����
LONG);

  set("exits", ([ 
 "east":__DIR__"hgdajie3",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer3":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

