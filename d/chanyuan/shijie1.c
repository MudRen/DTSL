
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ��");
  set ("long", @LONG
������һ��ʯ�ס������Ǿ�����Ժ�İ�ʯ�㳡������ȥ������Ժ��
������ˡ���������������������о�֮��������������ƴ�ң����֪
��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"baishiguangchang",
	  "eastup":__DIR__"wenshudian",
  
         ]));
 
set("outdoors","chanyuan");
  
  set("valid_startroom", 1);
  setup();
 
}

