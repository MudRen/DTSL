// /d/zhuojun/dadao3.c
// Room in �ÿ�
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ��˴���Ⱥϡ�٣�����Ҳ�����ĵġ�
LONG
        );
set("outdoors", "/d/zhuojun");
set("exits", ([
                "northwest":"/d/yuyang/chalu",  
                "southwest":__DIR__"dadao2",    
	]));
       setup();
	replace_program(ROOM);
}
