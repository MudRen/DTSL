// Room: /d/shaolin/shulin1.c
// by pishou

inherit ROOM;




void create()
{
    set("short", "������");
	set("long", @LONG
������һƬ�������п��ٵ�һ�յء���������ϡ�٣������Ե�ʮ��
�ľ����ߴ��������ס�˴��۵����⣬Ϊ�����ṩ��һ����Ȼ����Ϣ��
����
LONG
	);

	set("exits", ([
        "southeast" : "/d/taishan/wshandao2",
        "north" :__DIR__"shulin",
	]));

 	set("outdoors", "yuyang");
	setup();
	replace_program(ROOM);
}



