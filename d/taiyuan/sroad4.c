// /d/taiyuan/nroad1.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "ɽ��");
	set("long", @LONG
��˳�Ŵ������ǰ�ߣ��������߽���ɽ���·Ҳ��ʼ������ƽ��
������·˳��ɽ��������ǰ���죬���߶���ï�ܵ����֣�ż����������
����������С�	
LONG
        );
set("outdoors", "/d/taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "westdown":__DIR__"sroad3", 
                "northeast":__DIR__"sroad5", 
                
	]));
       setup();
	replace_program(ROOM);
}
