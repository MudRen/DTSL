
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ����");
  set ("long", @LONG
������һ����̣��������ǳ������������������ǽ��̨������һ
�Ȼ�ѿҶ������ֻ��һ�ҡ���������ǳ��ã��ܶ���������Ȳ����죬
����С��æ����ͣ��
LONG);

  set("exits", ([ 
  "west":__DIR__"baihujie3",
         ]));
  set("objects",([
	  __DIR__"npc/chaguan_laoban":1,
	  ]));
  set("valid_startroom", 1);
  set("resource/water",1);
  setup();
 
}

