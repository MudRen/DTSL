inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
������һ��Сɽ�����򶫱�ңң��ȥ�����Կ�����ܭ�ǣ�������ң
ң��ȥ�����Կ��������Ǻ�һ����Ժ��
LONG );

	set("exits", ([
                         "eastdown"      : __DIR__"xiaolu2",
                         "westdown"      : __DIR__"shanlu1",
		
	]));
	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



