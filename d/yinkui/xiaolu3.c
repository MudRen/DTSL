
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·������������Ѿ������ˡ����Ｘ��û��ʲô�ˣ�
һƬ������ɪ�����ա������Ӳݴ�����ֻ�м�ֻҰ�ò�ʱ����Ľ�ǰ��
����
LONG);

  set("exits",([
	  "northwest":__DIR__"xiaolu2",
	  "southeast":"/d/xiangyang/dalu1",
	  
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

