
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����Ǿ�����Ժ��С·����������Ժ�ĳ��������ﴫ������ķ���
���������������о�֮��������������ƴ�ң����֪��Զ������������
��Ժ��
LONG);

  set("exits", ([ 
	  "eastup":__DIR__"changlang5",
	  "west":__DIR__"chufang",
     ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

