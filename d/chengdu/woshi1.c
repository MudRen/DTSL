
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƕ��𱤵ı������͵������ˡ����ϵı�����ú����롣�Ա�
������������ط����ķ��ı������￴�������࣬�ƺ��Ǹոմ�ɨ����
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"changlang1",
       ]));
  set("objects",([
	  __DIR__"npc/xiehui":1,
	  ]));
set("no_clean_up",1);
  set("valid_startroom", 1);
  setup();
 
}
