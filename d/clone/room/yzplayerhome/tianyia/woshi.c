
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","����");
	set("long", @LONG
���������˷򸾵����ҡ��м����һ�Ŵ󴲣����ϵı����
���������롣�ұ���һ���¹����ӵ������һ������ (chair)
��һ��д��̨(desk)��������ż����顣�������Ӥ�����ˡ�
LONG);
    set("exits", ([
	        "enter" : __DIR__"yingershi",
	        "down":__DIR__"shanzhuang",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
