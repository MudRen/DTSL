
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
�����������ȡ����ȵ�ǽ���ϻ���һЩɽˮ��������������������
�ǳ���������֮�֡�������һ��ʯ·���������߸���һ�����ȣ�ͨ����
���ط���
LONG);
	set("exits", ([
	     
		"north" :__DIR__"shilu2",
		"east":__DIR__"echanglang1",
		"west":__DIR__"wchanglang1",
		
	]));

        set("objects",([
			__DIR__"npc/shanyan":1,
			]));
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

