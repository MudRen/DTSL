
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ϻ���");
  set ("long", @LONG
���������ݳǵ��Ϻ��̡��ϱߴ���һЩ�������������������������
�����ʯ��ᾣ��β����������һ����ɡ������Ͼ������ݵ��ϴ���ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"donghudi4",
 "southeast":__DIR__"nandajie1",
 "west":__DIR__"nanhudi",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

