
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��Ϣ��");
  set ("long", @LONG
�������μұ�������ϰ���պ���Ϣ�ĵط������ϵı�����Щ���ң�
�м����μұ��ĵ�������������˯��������΢�����������������
��������Щ���ˡ�
LONG);

  set("exits", ([ 

   "north":__DIR__"wuchang",
     ]));
  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

