
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
  
	  "northwest":__DIR__"xiaojing2",
	  "southeast":__DIR__"xiaolou",
      ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
