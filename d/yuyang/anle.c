


inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
��������������ɽ���صıؾ�֮·�����ְ��ǰ��ֵĵ�һ����
��ǰ���죬��һ������ɱʹ���ְ����Ҫ����ȫ���������ڶ����Ľ���
�������𼫴��𶯡�
LONG);
	
	set("exits", ([
		"north" : "/d/shanhaiguan/dadao1",
                "south" : __DIR__"eroad",
                "northeast" : __DIR__"tulu2",
                "southwest" : __DIR__"shandao8",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
