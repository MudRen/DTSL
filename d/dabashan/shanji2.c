
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һ��ɽ����������ƶ��ͣ�һ��С�ģ��ͻ�ˤ�����������
���¡������Ǹ�Сɽ�£�����������ɽ��·��
LONG);

  set("exits", ([ 

   "eastdown":__DIR__"shanpo",
   "westdown":__DIR__"shanlu5",
           ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}
