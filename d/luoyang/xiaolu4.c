
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����������������Ժ�������������������˵����赾ͷ��ھ�
����Ժ���������дȺ���ի�������棬����û�����������ᡣ
LONG);

  set("exits", ([ 
	  "east":"/d/chanyuan/miaodoor",
	  "southwest":__DIR__"xiaolu3",
  
         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

