
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����������ڵ�һ��С·�����߲�ʱ�����������������ƺ�����
�����̡��ϱ�ȴ��ʱ����������������
LONG);

  set("exits", ([ 

  "west":__DIR__"xiaolu2",
  "east":__DIR__"haitan",
  "northeast":__DIR__"zhifatang",
  "south":__DIR__"fenzangpeng",
       ]));
  set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

