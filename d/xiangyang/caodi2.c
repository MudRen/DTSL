
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�����͵Ĳݵأ������Ѿ���һ���ɹ������˲ȳ���һ��
С·�������кܶ�Ư����Ұ�����ѹ�Ӣ��ֲ���ʱ��Ұ�ô���Ľ���
������
LONG);

  set("exits", ([ 

  "north":__DIR__"caodi3",
  "south":__DIR__"guanlu2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","xiangyang");
  setup();
 
}

