
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֡�������ȥ����Ȼ���ּ�����ʬ���м�ֻҰ������
��Ը��õ�ʬ�塣��һ����ģ��ӿ����н��ĽŲ���
LONG);

  set("exits", ([ 
 "east":__DIR__"shulin5",
 "southwest": "/d/xingyang/tulu3",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

