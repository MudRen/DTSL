
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������С·���ܶ�����Ϊ�˱����¹ʣ����Գ˴�������ȥ��ʦ��
����羰������ɽˮ�续���������¡������кܶ�Ư����Ұ�����ѹ�Ӣ
��ֲ���ʱ��Ұ�ô���Ľ���������
LONG);

  set("exits", ([ 
  "west":__DIR__"xiaolu1",
  "northeast":__DIR__"xiaolu3",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

