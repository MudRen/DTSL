
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƿ��������㫑�����ҡ����ϵı�������������롣ǽ�Ϲ�
��һ�ڱ�������ױ̨�Աߵ������ϻ�����һЩ�鼮������İ������ش�
�����������ס�һ�ɵ���������������������ҡ�
LONG);

  set("exits", ([ 
	  "south":__DIR__"feiniao_yuan",
    ]));

  
  set("valid_startroom", 1);
  setup();
 
}

