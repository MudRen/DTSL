inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����������Ĵ���������Լ����������������������
�����߾����Ǻ��ϵ����������������ĳ������˲��ϣ���Ϊ���̵�ԭ
������·�ϻ���һ�Ӷӹٱ�������ż��������Ĺٱ��ɳ۶���������һ
Ƭ������
LONG );

	set("exits", ([
               "southwest"      : __DIR__"xiaolu1",
               "southeast"      : __DIR__"tulu8",
             	]));

 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



