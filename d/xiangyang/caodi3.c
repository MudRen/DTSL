
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�����͵Ĳݵأ������Ѿ���һ���ɹ������˲ȳ���һ��
С·�������кܶ�Ư����Ұ�����ѹ�Ӣ��ֲ���ʱ��Ұ�ô���Ľ���
������ǰ�治Զ����һƬ���֡�
LONG);

  set("exits", ([ 
  "north":__DIR__"shulin",
  "south":__DIR__"caodi2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","xiangyang");
  setup();
 
}

