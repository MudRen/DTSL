

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
                "west" : __DIR__"eroad4",
                "southeast" : __DIR__"edao4",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
