
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǿ�����Ժ�ĳ��ȡ���������Ժ��������۱����������Ժ
�Ĳؾ������������о�֮��������������ƴ�ң����֪��Զ��������
������Ժ��
LONG);

  set("exits", ([ 
	  "north":__DIR__"changlang3",
	  "southdown":__DIR__"daxiong-baodian",
         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

