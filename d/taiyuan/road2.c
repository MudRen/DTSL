// /d/taiyuan/road2.c
// Room in ̫ԭ
// modify by yang

#include <room.h>
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵���������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
set("outdoors", "/d/taiyuan");
set("exits", ([
                "east":__DIR__"road1", 
                "southwest":__DIR__"road3", 
                
	]));
       setup();
       replace_program(ROOM);
}


