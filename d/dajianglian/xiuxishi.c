
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","��Ϣ��");
  set ("long", @LONG
�����Ǵ����ֶ����Ϣ�ҡ������Ѿ��кܶ������������Ϣ�ˡ�
���������������Щ���ˣ�������˯��һ����
LONG);

  set("exits", ([ 
	  "west":__DIR__"shalu",
	     ]));
set("sleep_room",1);
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

