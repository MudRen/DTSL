// /d/zhuojun/dadao1.c
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
                //"northeast":__DIR__"dadao2",  
                "south":__DIR__"beimen", 
                "northwest":"/d/yuyang/chalu",   
	]));
       setup();
	replace_program(ROOM);
}
