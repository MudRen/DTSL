
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

  "northwest":__DIR__"shulin9",
  "northeast":__DIR__"shulin5",
  "north":__DIR__"shulin7",
    ]));
  
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

