
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ���������Ա��м�����ܣ�������ɢ�ط��˼������顣��
�ϻ����˻ҳ��������Ѿ����û���������ˡ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east":"/d/chengdu/dadian",
	]));
	set("objects",([
	  __DIR__"npc/heshang":1,
	  ]));

	setup();
	replace_program(ROOM);
}

