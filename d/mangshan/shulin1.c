
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ����
��ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�������
�ڵ�˿��Ҳ�ޡ����ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG);

  set("exits", ([ 

  "east":__DIR__"shulin1",
 "west":__DIR__"shulin1",
 "south":__DIR__"shanlu3",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

