
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǽ������������ˡ����ϵı�����ú����롣�Աߵ���������
��ط����ķ��ı������￴�������࣬�ƺ��Ǹոմ�ɨ������ʱ��Ѿ��
���������������
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"changlang2",
       ]));
  set("objects",([
	  __DIR__"npc/xiewenlong":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}
