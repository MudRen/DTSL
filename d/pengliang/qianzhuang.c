inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����������Ƶ�Ǯׯ��һ����߸ߵĹ�̨���������ǰ����
̨�ϰ���һ������(paizi)����̨�������ϰ壬һ˫�����������´�����
�㡣
LONG
	);

	set("item_desc", ([
		"paizi" : "ͯ������\n",
	]));
	
	set("exits", ([
		"south" : __DIR__"xidajie",
	]));
          set("objects", ([
                __DIR__"npc/qian" : 1
	]));
	setup();
	replace_program(ROOM);
}

