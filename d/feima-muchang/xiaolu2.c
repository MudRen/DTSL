
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�������Ǹ߸ߵ�դ�����������Ÿ��ָ�������ƥ��
�м�����������������ι�������ǡ�Զ�����Կ��������������м�����
�������ĵ������������������
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"huayuan1",
	  "southeast":__DIR__"xiaolu1",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

