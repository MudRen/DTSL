
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"ʯ��"NOR);
	set("long", @LONG
������һ���������ϵ�ʯ�ס�����ǰ�߾���ƽ̹����ʯ·�ˡ�����
������ϰ���յĺ��������Ա߻�����һ��ʯ����bei����
LONG);
	set("exits", ([
	     
		"northdown" :__DIR__"shijie2",
		"south":__DIR__"shilu1",
		
	]));
	set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
	set("item_desc",([
		"bei":GRN"����ãã\nƮȻ����\n"NOR,
		]));
        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

