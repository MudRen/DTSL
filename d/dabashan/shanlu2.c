
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����Ǵ��ɽ��һ��ɽ·��������һ��ɽ����������һ�����֣���
���кܶ�ɽ����Ҳ��֪��������û�е�����
LONG);

  set("exits", ([ 

   "southwest":__DIR__"shulin",
   "enter":__DIR__"shandong1",
   "north":__DIR__"shanji1",
         ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

