
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
������һƬï�ܵ����֡��ϱ���һ��ɽ�¡������������壬����û
��ʲô�������
LONG);
	set("exits", ([
		"northwest":__DIR__"haitan2",
                "south":"/d/clone/room/lingwu/dongming/shanya",
		"east":__DIR__"pubu",
	]));
	set("objects",([
		__DIR__"npc/shangwannian":1,
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

