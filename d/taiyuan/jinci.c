// /d/taiyuan/jinci.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
������̫ԭ�Ľ������������������ս�ң������Ѿ��ƾɲ�������
��û��ʲô���������ˡ�
LONG
	);
set("exits", ([
                "west" : __DIR__"beidajie1", 
	]));
 set("objects",([ __DIR__"npc/girl2":1,]));
       setup();
	replace_program(ROOM);
}	
