inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����������Ĵ���ϡ������������������������ӵ����̣�
���Ŵ󳵵���������������ǳ����֡�������Ϊս�ҵ�ԭ�����Ѿ�����
�����������ˡ�
LONG);

	set("exits", ([
		"west":"/d/xingyang/dadao4",
                "south":__DIR__"beichengmen",
                "east":"/d/yangzhoubei/shalu2"
	]));

 	set("outdoors","/d/pengliang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}


