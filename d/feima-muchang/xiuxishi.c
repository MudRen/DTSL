
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ϣ��");
  set ("long", @LONG
�����Ƿ�����������Ϣ�ҡ����ɻ���˹��˶�������˯����Ϣ��
ֻ������������죬�������źܶ��ˡ����������������Щ�����ˡ�
LONG);

  set("exits", ([ 
	  "south":__DIR__"caiyuan",
    ]));
  set("sleep_room",1);
  
  set("valid_startroom", 1);
  setup();
 
}

