
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
�����Ǵ��ɽ��һ��ɽ�¡����������б���㲻���ӱ�С��������
���������ȥ��
LONG);

  set("exits", ([ 

   "south":__DIR__"shanlu1",
   "northeast":__DIR__"shanfeng",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

