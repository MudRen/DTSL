
inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����������С·����Ϊ�Ĵ��Թž��Ǹ���֮�أ����Է���
��ȥ�����ܵ��������������ࡣ�����Ǵ��У�����ʮ���ﴦ����������
�񶼳ɶ��ˡ�
LONG);
	

	set("exits", ([
        "north" : __DIR__"dananmen",
		"southwest" : __DIR__"tulu2",
	]));

	setup(); 
	replace_program(ROOM);
}
