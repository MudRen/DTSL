

inherit ROOM;


void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����·�����������������ӵ����̣����Ŵ󳵵��������
�������ǳ����֡���ʱ����������������߷ɳ۶���������һ·����
������������ͨ��ɽ���صĴ����������ͨ���ÿ��Ĺٵ���
LONG
	);
	
	set("exits", ([
                "north" : __DIR__"zhuojun",
                "southeast" : __DIR__"eroad4",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
