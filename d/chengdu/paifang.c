
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ�Ʒ�");
  set ("long", @LONG
������һ��ʯ�Ʒ������顰�������塱�ĸ����֡�������Ȼ����
����һ������ȴ���������κμ�а֮�£��������ĸ��ֱ����𱤵�����
�����С��м������𱤵��Ӳ�ʱ��������ԴҴҶ�����
LONG);

  set("exits", ([ 
  
	  "south":__DIR__"shilu",
	  "north":__DIR__"zhaobi",
         ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
