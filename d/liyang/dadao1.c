inherit ROOM;

void create()
{
	set("short", "�����");
set("long",@LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡���ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�
LONG );

	set("exits", ([
		"northeast"      : "/d/xucheng/dadao",
		"southwest"      : __DIR__"dadao2",
              "east":"/d/xucheng/edao",
		
	]));


 	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}



