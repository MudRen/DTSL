inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡��ϱ��Ѿ������ƺӵı����ˣ����������ƺ���ˮ��������
LONG );

	set("exits", ([
               "east"      : __DIR__"dadao7",
               "southwest":__DIR__"dadao9",
		
	]));


 	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}



