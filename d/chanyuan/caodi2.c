
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء�ƽʱ�������˵���������ǰ������Ժ������Ϣ��
�ط�����ʱ����˯�����������������������о�֮��������������ƴ�
ң����֪��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "westup":__DIR__"changlang3",
	  "southeast":__DIR__"caodi3",
	  "enter":__DIR__"anfang",

         ]));
    set("objects",([
	  __DIR__"npc/buju":1,
	  ]));
  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

