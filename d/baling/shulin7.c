
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ����
��ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�����
���ڵ�˿��Ҳ�ޡ������������ƺ���Ϫˮ������������
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shulin6",
  "southwest":__DIR__"shulin9",
  "south":__DIR__"shulin8",
    ]));
  
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

