
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ��ı���֡�����ͨ�򱱳��ţ��ϱ��Եúܷ�æ���м���С
�̷����ų�����������߹������ﻹ��ͣ��ߺ���š�ֻ�������ٱ�ҫ��
�����ش���������߹�������ش�����·�ϵ����ˡ�
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"beidajie4",
		"south" : __DIR__"center",
		
	]));
	set("objects",([
	  "/d/clone/npc/songyuhua":1,
	  ]));

	setup();
	replace_program(ROOM);
}

