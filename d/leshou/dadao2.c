// /d/zhuojun/dadao2.c
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
                "northeast":__DIR__"dadao3",  
                "southwest":__DIR__"dadao1",    
	]));
       setup();
	replace_program(ROOM);
}
