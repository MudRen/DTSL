inherit ROOM;

void create()
{
	set("short", "��˧������");
	set("long", @LONG
��������˧���Ĵ������������߰��ű����ܣ����Ϸ�������Ѫ����
ӳ�żܺ��ս�죬����ҫ�ۡ����������˧�칫�ͻ�͵ĵط���
LONG );
	set("exits", ([
		"south" : __DIR__"yuanzi",
        "enter":"/d/clone/room/cityroom/pengliang",
	]));
	setup();
	replace_program(ROOM);
}

