// /d/suiye/dadao2.c
// Room in ��Ҷ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "���ԭ");
	set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ�
�治���ߣ�������ƥ�����������ǵĺ����⡣
LONG
        );
set("outdoors", "/d/suiye");
set("exits", ([
                "north":__DIR__"dadao1",  
                "northeast":__DIR__"caoyuan",  
                 "south":"/d/tuyuhun/shamo3",    
	]));
       setup();
	replace_program(ROOM);
}
