
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ��");
  set ("long", @LONG
������һ��ʯ�ס������Ǿ�����Ժ�����������ȥ������Ժ��
�������ˡ���������������������о�֮��������������ƴ�ң����֪
��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"wenshudian",
	  "eastup":__DIR__"wuliangdian",
  
         ]));
 
set("outdoors","chanyuan");
  
  set("valid_startroom", 1);
  setup();
 
}

