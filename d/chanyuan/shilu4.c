
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ·");
  set ("long", @LONG
�����Ǿ�����Ժ��ʯ·�������߾�����Ժ�ĺ����ˡ�����û��ʲô
�ˣ�����û������������������о�֮��������������ƴ�ң����֪
��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "east":__DIR__"shilu5",
	  "west":__DIR__"tongdian",
  
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

