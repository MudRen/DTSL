// /d/yuyang/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "��ƽ��");
	set("long", @LONG
��ƽ�������������֡��ÿ�����������Ϊ�����������ǣ���߿�
��������Ϊ�����������������֮�ף���Ϊ�������¾���ó�׵����ģ�
����ƽ���������λ��Ҳ�Ǳ��ұ���֮�ء�
LONG
	);

	set("exits", ([
                "south" : __DIR__"edao3",
                "west" : __DIR__"eroad2",
                //"southwest":"/d/xucheng/xiaolu2"
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


