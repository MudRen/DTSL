
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������������������µĴ����ڳ��軪�������������
��֮״����ΰ׳����������ԡ� 
LONG);

  set("exits", ([ 
 "north":__DIR__"chengendian",
 "south":__DIR__"chongjiaodian",
        ]));
  
  set("valid_startroom", 1);
  setup();
 
}

