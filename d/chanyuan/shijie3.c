
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ��");
  set ("long", @LONG
������һ��ʯ�ס������Ǿ�����Ժ�����������ȥ������Ժ�Ĵ�
�۱����ˡ���������������������о�֮��������������ƴ�ң����֪
��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"wuliangdian",
	  "eastup":__DIR__"daxiong-baodian",
  
         ]));
 
set("outdoors","chanyuan");
  
  set("valid_startroom", 1);
  setup();
 
}

