// /d/shanhaiguan/dadao1.c
// Room in ɽ����
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ��������߾���ɽ�����ˡ�
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "north":__DIR__"nanchengmen",  
            "southeast":"/d/yuyang/tulu3",
                "south":__DIR__"dadao1-2",

	]));
       setup();
	replace_program(ROOM);
}
