
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ����
��ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�������
�ڵ�˿��Ҳ�ޡ����ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ�����������
���ϵľ����ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"shalu3",
  "southeast":__DIR__"tree2",
 "northwest":"/d/quest/jinlongzhang/suishilu1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

