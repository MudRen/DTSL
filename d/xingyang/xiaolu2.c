inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�˼���ͨ������Ժ��ɽ��һ��С·���򶫿��Ե����ܭ�ǣ��㾲
��������פ���������ƺ����������洫�����о���������
LONG );

	set("exits", ([
                         "northeast"      : __DIR__"xiaolu1",
                         "westup"      : __DIR__"shanbao1",
		         "southwest"      : "/d/outyang/shalu4",
	]));
	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



