
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","����");
	set("long", @LONG
����һ��С��������Ȼ���󣬵��ǹ���ư�裬���ν��ף���
����ȫ����̨�϶��������ʹϹ��߲ˣ������Ϻ���������಻�ң�
��ʮ�ָɾ����롣
LONG);
    set("exits", ([
	        "south":__DIR__"shanzhuang",
	      
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
