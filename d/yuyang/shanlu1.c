// /d/yuyang/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��С������Ĵ�ɽ���ı������£�б�²������ɵ���ȥ������
������ġ������Ӳݴ�����ʮ�ֻ���������ɢ�ż���Ǻ���
LONG);

	set("exits", ([
               "westdown" : __DIR__"xiagu",
               "southup" : __DIR__"shanding",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


