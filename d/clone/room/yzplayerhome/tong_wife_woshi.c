
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIM"����"NOR);
	set("long", @LONG
������˪���ӵ����ҡ��м����һ�Ŵ󴲣����ϵı������
�������롣�ұ���һ����ױ̨����ױ̨���Ա߻��������ѵ�����
����ž��Ӻ���Ů���֡���ͷ�ϻ����ż����飬�������ƺ���̸
�۵������°����µ����ݡ����ӵ������һ���¼ܣ��������
�����·���
LONG);
    set("exits", ([
	        "east":__DIR__"tong_and_wife",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
