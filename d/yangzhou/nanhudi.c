
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ϻ���");
  set ("long", @LONG
���������ݳǵ��Ϻ��̡��ϱߴ���һЩ�������������������������
�����ʯ��ᾣ��β����������һ����ɡ��������Ϲ��˵ڶ��ε̾���
���ݵ��ϴ���ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"nanhudi2",
 "northwest":__DIR__"xihudi",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

