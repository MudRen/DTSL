// /d/shanhaiguan/dadao1.c
// Room in ɽ����
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
������λ��Ͽ��һ���ɽ�Ƹߴ���������ɽ������ռɽΪ�ϵ�ɽ��
ζ�����߱����·�����������һ������ߵ�ʿ¥����Բ�θߴ����ɵ�ʯ
��Χǽ����άΧǽ����ʿ�����࿪չ�����������ʵ��˹㳡�����ǳ���
ͣפ�ĵط���
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "eastdown":__DIR__"qingshilu",  
                "west":__DIR__"kezhan",
                	]));
       setup();
	replace_program(ROOM);
}
