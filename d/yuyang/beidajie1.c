
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң���
���˶����ϱ���ȥ��������һ�����ֵĹ㳡��������һ��������¡��ҩ
�̣�һλ���Ƶ��ϰ������������һ��Ǯׯ�������������������Ľ�
��������
LONG
	);
        set("outdoors", "/d/yuyang");

	set("exits", ([
		"south" : __DIR__"guangchang",
		"west" : __DIR__"qianzhuang",
		"north" : __DIR__"beimen",
		"east" : __DIR__"yaopu",
	]));
	set("objects",([
	 __DIR__"npc/xiaonvzi":1,
	 ]));
	setup();
	replace_program(ROOM);
}

