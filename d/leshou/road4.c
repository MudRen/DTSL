// /d/zhuojun/road6.c
// Room in �ÿ�
// modify by yang

inherit ROOM;


void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡���ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡���������������ȥ��ԶԶ�ľͿ����������ԭ����
����ͨ��̫ԭ��
LONG );
	set("exits", ([
		"west" : "/d/taiyuan/road7",
		"east" : __DIR__"road3",
	]));
	
 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



