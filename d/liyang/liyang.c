inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
����Ǿ������������������Ǳ��ұ���֮�أ��򱱿��Խ����ӱ���
ɽ����������ͼ������������������֮�ƣ��˿��غ��ϣ����ɹ�������
��ͼ���塣
LONG );
	set("outdoors", "liyang");
	set("exits", ([
		"north" : __DIR__"dadao4",
		"south" : __DIR__"dadao6",
                "west" : __DIR__"dadao5",
                "east" : __DIR__"qingshilu",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
	setup();
}
