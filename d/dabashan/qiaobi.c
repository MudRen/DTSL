
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ͱ�");
  set ("long", @LONG
�����Ǵ��ɽ��һ���ͱڡ�������������Ԩ�����������������Ȳ�
������д����
LONG);

  set("exits", ([ 

   "southeast":__DIR__"caishichang",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

