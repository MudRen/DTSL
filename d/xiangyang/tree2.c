
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

  "northwest":__DIR__"tree1",
  "southwest":__DIR__"caodi1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

