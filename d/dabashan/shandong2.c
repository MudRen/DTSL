
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һ��ɽ��������ں����ģ����ֲ�����ָ���ƺ���ʲô������
�㲻���ӱ�С��������
LONG);

  set("exits", ([ 

   "southwest":__DIR__"shandong1",
            ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

