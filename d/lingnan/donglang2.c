
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƕ��ȡ��ȱ��ϻ��˺ܶ�ɽˮ���������п��Կ����μұ�����
��ˮƽ��Ρ���ʱ��һЩ�μұ����Ӵ�������ԴҴ��߹���
LONG);

  set("exits", ([ 

  "west":__DIR__"donglang1",
  "east":__DIR__"donglang3",
       ]));
  set("objects",([
	  __DIR__"npc/yahuan":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

