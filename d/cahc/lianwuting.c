
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
���߽�һ��������Ĵ�������ͨ�˳�Ϊһ�����ӡ��������ߵı�
�����ϰ����˸��ֱ��С�
LONG);

  set("exits", ([ 
 "southwest":__DIR__"houhuayuan",
        ]));
 

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

