
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","�䳡");
  set ("long", @LONG
�����Ǵ����ֶ�����䳡���м���������������ϰ���ա��Ա���
����ʦ��������ָ�����ǡ�
LONG);

  set("exits", ([ 
	  "east":__DIR__"caodi",
	     ]));
set("outdoors","dajiang");
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

