
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·������ش�����������֮�䣬����ȴ���Ǻܶࡣ��
��羰������ɽˮ�续���������¡������кܶ�Ư����Ұ�����ѹ�Ӣ��
ֲ���ʱ����������ͷ�Ϸɹ���
LONG);

  set("exits",([
	  "westup":__DIR__"xiaolu1",
          "southeast":__DIR__"xiaolu3",
	  "northwest":__DIR__"fendi",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

