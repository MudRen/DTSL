
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ĸ��");
  set ("long", @LONG
������̩ɽ�Ķ�ĸ����������ȥ�����кܶ������������ʵǣ�ɽ��
���˿������Ѿ���������һ���ˡ�
LONG);

  set("exits", ([ 

   "northup":__DIR__"hutiange",
   "southdown":__DIR__"shanlu3",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

