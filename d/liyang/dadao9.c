inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡��ϱ߾��ǻƺӵı����ˡ�
LONG );

	set("exits", ([
               "northeast"      : __DIR__"dadao8",
               "southwest":"/d/luoyang/huanghe_dukou2",
		
	]));


 	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}



