
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǿ�����Ժ�ĳ��ȡ�ǽ���ϻ��źܶ���񣬿���ȥ����������
һ�����ǳ��������Ĺ���֮�֡����������о�֮��������������ƴ�ң
����֪��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "enter":__DIR__"cangjing-fang",
	  "south":__DIR__"changlang2",
	  "westdown":__DIR__"caodi1",
	  "eastdown":__DIR__"caodi2",
         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

