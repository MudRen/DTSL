inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡���ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�
LONG );

	set("exits", ([
               "northeast"      : __DIR__"dadao6",
               "south"      : "/d/xingyang/huanghe_dukou1",
               "west":__DIR__"dadao8",
	       "east": "/d/xucheng/edao9",
			]));


 	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}



