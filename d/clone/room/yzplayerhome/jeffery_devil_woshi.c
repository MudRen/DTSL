
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIM"����"NOR);
	set("long", @LONG
��������ң�ӵ����ҡ��м����һ�Ŵ󴲣����ϵı������
�������롣�ұ���һ����ױ̨����ױ̨���Ա߻��������ѽ�����
����ž��Ӻ���Ů���֡���ͷ�ϻ����ż����飬�������ƺ���̸
�۵������°����µ����ݡ����ӵ������һ���¼ܣ��������
�����·���
LONG);
    set("exits", ([
	        "south":__DIR__"jeffery_devil",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
