inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡���ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�������������������ˡ�
LONG );

	set("exits", ([
               "west"      : __DIR__"dongmen",
               "east"      : "/d/pengliang/dadao1",
               "south"      : __DIR__"dadao5",
		
	]));


 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



