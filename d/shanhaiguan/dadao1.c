// /d/shanhaiguan/dadao1.c
// Room in ɽ����
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ�����
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "north":__DIR__"dadao1-1",  
                "south":"/d/yuyang/anle",

	]));
       setup();
	replace_program(ROOM);
}
