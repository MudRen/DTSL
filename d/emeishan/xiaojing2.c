
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
������һ����ɽ��С�����㲻��Ϊ��üɽ�ľ�ɫ���������������
�Կ���ɽ�µķ�⡣
LONG);

  set("exits", ([ 
 "northeast":__DIR__"caodi1",
 "westdown":__DIR__"xiaojing1",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

