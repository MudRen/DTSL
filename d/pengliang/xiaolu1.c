#include <room.h>

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
		"southeast"  : __DIR__"shanlu2",
		"northwest"   : __DIR__"shanlu3",
		"southwest"   : __DIR__"dadao1",
	]));
	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

