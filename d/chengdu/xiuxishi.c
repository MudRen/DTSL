
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ϣ��");
  set ("long", @LONG
�����Ƕ��𱤵ĵ���ƽʱ��Ϣ�ĵط������ϵı�����Щ�����ˣ���
�����������ڴ���˯�ž���������΢�����������������������Щ��
�ˡ�
LONG);

  set("exits", ([ 
	  "south":__DIR__"wuchang",
        ]));
  set("sleep_room",1);
set("valid_startroom", 1);
  setup();
 
}
