

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
                "northwest" : __DIR__"eroad1",
                "east" : __DIR__"yincheng",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
