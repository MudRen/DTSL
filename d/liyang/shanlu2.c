inherit ROOM;
void create()
{
	set("short", "����С·");
	set("long", @LONG
���Ƕ����ϵ�һ���Ӳݴ�������С·��������ƽʱûʲô�˼���
·�߿��Ų�֪����Ұ�������ߵ�������Ȼ�ߴ�ͦ�Ρ�����͸�����յ�
�������ǰ߲߰�����Ӱ�ӡ�
LONG );
	set("exits", ([
		"southwest"     : __DIR__"shanlu3",
		"northdown"     : __DIR__"shanlu1",
	]));
	set("objects", ([
		__DIR__"npc/yetu" : 1,
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

