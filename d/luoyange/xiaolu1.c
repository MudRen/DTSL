
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������С·����������Ѿ����Ǻܶ��ˡ������������ˡ�����
�羰������ɽˮ�续���������¡������кܶ�Ư����Ұ�����ѹ�Ӣ��ֲ
���ʱ��Ұ�ô���Ľ���������
LONG);

  set("exits", ([ 
  "west":__DIR__"guanlu2",
  "east":__DIR__"xiaolu2",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

