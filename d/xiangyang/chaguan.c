
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
������������һ��С��ݡ���Ȼ��С�����⣬��ÿ�������Ŀ��˲�
���١���������⻹����ԡ��м�������������Աߵ�����̸��������
����ʽ����С����ר�ĵ����Ų衣
LONG);

  set("exits", ([ 
 "east":__DIR__"beidajie3",
        ]));
 set("objects",([
	 __DIR__"npc/cha":1,
	 ]));
 set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

