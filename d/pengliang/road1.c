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
                "southeast":"/d/yangzhoubei/huanghebei",
		"north": "/d/leshou/road5",
		
	]));


 	set("outdoors", "penliang");
	setup();
	replace_program(ROOM);
}



