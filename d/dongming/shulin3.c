
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
������Ƭ���֡����Ｘ��û��ʲô�ˡ�����ż�����������������
����������
LONG);
	set("exits", ([
		"west":__DIR__"shulin1",
		]));
        set("objects",([
          __DIR__"npc/shangming":1,
          ]));
        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

