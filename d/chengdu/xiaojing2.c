
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��С��");
  set ("long", @LONG
������һ����С�����������ۡ��������˺ܶ໨�ݣ�����Ʒ�ֲ�
�Ǻܶ࣬�ֻ�����ͷף�ɫ������������������Ŀ��
LONG);

  set("exits", ([ 
  
	  "northeast":__DIR__"xiaojing1",
	  "southeast":__DIR__"xiaojing3",
      ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
