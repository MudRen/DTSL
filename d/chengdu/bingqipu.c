
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�ұ����̡����������ս��ʹ���������ܺá��Ա߻���
����������ѡ����ǽ�ϵı�������������˺ܶ�ոմ���õı�������
�ֵ��������ȡ�
LONG);

	set("exits", ([
		"west" : __DIR__"nandajie2",
	]));
	set("objects",([
		__DIR__"npc/tiejiang":1,
		]));

	setup();
	replace_program(ROOM);
}

