
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�������Ǹ߸ߵ�դ�����������Ÿ��ָ�������ƥ��
�кܶ���ǣ��������ȥ��Զ�����Կ��������������м�������������
�������������������
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"xiaolu2",
	  "southeast":__DIR__"podao2",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

