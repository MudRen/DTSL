
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǿ�����Ժ�ĳ��ȡ���������Ժ��������۱��ǽ���ϻ���
�ܶ���񣬿���ȥ����������һ�����ǳ��������Ĺ���֮�֡�
LONG);

  set("exits", ([ 
	  "north":__DIR__"daxiong-baodian",
	  "south":__DIR__"changlang5",
       ]));

  
  set("valid_startroom", 1);
  setup();
 
}

