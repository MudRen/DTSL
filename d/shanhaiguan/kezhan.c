// /d/shanhaiguan/dadao1.c
// Room in ɽ����
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
���߽�¥�����ͷ�������ʮ��֮�࣬�쾮��Χ�ǻ����Ļ��ȣ�
����������ߡ�������������ЪϢ̸�죬����������д���ζ�����쾮
�����Ǹ�������ɵĴ�ˮ�ء�
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "east":__DIR__"yinmayi",  
                "west":__DIR__"wenquan",
                  "north":__DIR__"beifang",  
                 "south":__DIR__"nanfang",  
                	]));
       setup();
	replace_program(ROOM);
}
