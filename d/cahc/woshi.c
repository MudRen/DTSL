
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ϣ��");
  set ("long", @LONG
��������߸�������Ϣ�ĵط������ϵı�������������룬�м���
��������������˯�����������ﲻ����Щ���ˡ�
LONG);

  set("exits", ([ 
	  "east":__DIR__"tcgc",
       ]));

  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

