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
               "northeast"      : __DIR__"tulu6",
               "west"      : __DIR__"tulu8",
		
	]));

 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



