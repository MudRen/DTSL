
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","��Ϣ��");
  set ("long", @LONG
�����Ǻ�ɳ�����Ϣ�ҡ������������죬��ʱ�к�ɳ����˽�����
Ϣ�����������Ҳ������Щ���ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaolu4",
        ]));
  set("sleep_room",1);
  
  set("valid_startroom", 1);
  setup();
 
}

