// /d/yuyang/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��˳�Ŵ������ǰ�ߣ��������߽���ɽ�һ���Ǹ�������ĸ�ɽ
���룬һ���Ƕ��͵�ɽ�£�����Ͽ������ȥ���о���һ��ѣ�Σ��㲻��
С�ĵ����ߣ����˵��ٶ�Ҳ������������.	
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"shandao7",
                "northeast" : __DIR__"anle",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


