
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"����"NOR);
	set("long", @LONG
������һ������������������ͨ�����ĵط����������ܹ��ߺܰ���
�����Ǹ߸ߵ�Χǽ����ƾ���书�ж�߳����޷��ӳ�ȥ������վ�ż���
����������������Լ��������
LONG);
	
	set("no_fight", 1);
	set("no_exercise",1);
	set("no_respirate",1);

	set("valid_startroom", 1);
	setup();
}

