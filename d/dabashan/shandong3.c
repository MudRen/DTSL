
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

   "west":__DIR__"shandong1",
   "northeast":__DIR__"shandong4",
            ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

