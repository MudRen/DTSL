
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ɽ��");
  set ("long", @LONG
������ͨ��̩ɽ��ɽ������ɽ������Ϊ·�ܲ����ߣ������������
�˺��٣�̧ͷ��ȥ��̩ɽ���ʵ�ɽ���Ѿ������ƶˡ�
LONG);

  set("exits", ([ 

   "southdown":__DIR__"daizongfang",
   "northup":__DIR__"wshandao2",
        ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

