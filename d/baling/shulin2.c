
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ������
��ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�����
���ڵ�˿��Ҳ�ޡ������������ƺ���Ϫˮ������������
LONG);

  set("exits", ([ 

  "northeast":__DIR__"shulin1",
  "west":__DIR__"lu1",
  "southeast":__DIR__"shulin9",
    ]));
  
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}
