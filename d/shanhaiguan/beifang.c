// /d/shanhaiguan/dadao1.c
// Room in ɽ����
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "���᷿");
	set("long", @LONG
���ǵ������䱱�᷿�������������Ժ���ﰲ����һЩ, ������ʰ
�øɸɾ�����
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                 "south":__DIR__"kezhan",  
                	]));
       setup();
	replace_program(ROOM);
}
