
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ͨ�������¥��ʯ�ס�������һƬ��ݵء����ﾲ���ĵģ�
ƽʱû��ʲô������ֻ�м���Ѿ�ߴ������߹���
LONG);
	set("exits", ([
		"westup" : __DIR__"shijie2",
		
		"eastdown" : __DIR__"caodi3",
	]));

	setup(); 
	replace_program(ROOM);
}
