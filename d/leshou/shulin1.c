// Room: /d/shaolin/shulin1.c
// by pishou

inherit ROOM;




void create()
{
    set("short", "������");
	set("long", @LONG
������һƬ�������п��ٵ�һ�յء�������ϵ�һ��������ס��һ
·����������, �Եø���ƽ����
LONG
	);

	set("exits", ([
        "southeast" : __DIR__"eroad3",
        "north" : "/d/yuyang/shulin",
	]));

 	set("outdoors", "leshou");
	setup();
	replace_program(ROOM);
}



