
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"��԰"NOR);
  set ("long", @LONG
�����Ǹ�С��԰���������˺ܶ���ʻ�����Ȼ��԰���󣬵��ǻ���
Ʒ�ַ��࣬����ɫ���������������ޡ����һ�����ɫ����õ���һ����
��������������Ŀ.
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"caodi1",
	  "southeast":__DIR__"xiaolu2",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

