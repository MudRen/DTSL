
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ɵľ����������������ɵĸ����书�ؼ�����ͨ
�����ǲ��ܽ����ġ�
LONG);
  set("exits",([
	  "southwest":__DIR__"chitang",
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

