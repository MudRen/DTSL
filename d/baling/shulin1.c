
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ����
��ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�����
���ڵ�˿��Ҳ�ޡ�Զ���ƺ��м���������Ϣ��
LONG);

  set("exits", ([ 

  "east":__DIR__"shalu2",
  "southwest":__DIR__"shulin2",
  "west":__DIR__"xiaoxi",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

