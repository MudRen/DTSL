
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء�һ��紵�����ں����м�������ݵ���Ϣ���㲻
����һ�������
LONG);

  set("exits", ([ 
 "north":__DIR__"xiaolu1",
  "south":__DIR__"shalu",
       ]));
  set("objects",([
	  __DIR__"npc/youqiuyan":1,
	  ]));
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

