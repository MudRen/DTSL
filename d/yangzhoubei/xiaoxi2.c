
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","СϪ");
  set ("long", @LONG
������һ��СϪ���峺��Ϫˮ�������¡�������һ����·����֪��
ͨ��δ���Ϫ���̲�����Ұ��Ʈ�㣬��������Ư���ĺ�����
LONG);

  set("exits", ([ 
 "northeast":"/d/xingyang/tulu2",
 "west":__DIR__"xiaolu3",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

